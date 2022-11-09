#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esat_extra/imgui.h>
#include "data_base_controller.h"
#include "table.h"
#include "nfd.h"

void HelpMarker(const char* desc){
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

int CallbackGetTablesName(void *notused,int num_colums, char **data, char **colum_name){
  static int actual_pos = 0;
  char **tables_name;
  if(num_colums == 0 && data == nullptr && colum_name == nullptr) {
    int **aux = (int **)notused;
    *aux = &actual_pos;
  } else {
    tables_name = (char **) notused;
    for(int i=0; i < num_colums; i++){
      strcpy(tables_name[actual_pos], data[i]);
      actual_pos++;
    }
  }

  return 0;
}

DataBaseController::DataBaseController(){
  db_opened_ = false;
  table_selected_ = false;
  table_created_ = false;
  actual_table_ = nullptr;
  cols_name_inserted_ = false;
  error_message_ = nullptr;
  query_table_ = nullptr;
  pagination = 20;
  edit_popup_open_ = false;
  max_colums = 30;
  row_data_copy_ = (char**) malloc(sizeof(char*)*max_colums);
  for(int i = 0; i < max_colums; i++){
    row_data_copy_[i] = (char*) calloc('\0',sizeof(char)*120);  
  }

  memset(query_,'\0',501);
  memset(query_aux_,'\0',501);
  CallbackGetTablesName(&actual_pos_ref_,0,nullptr,nullptr);
}

DataBaseController::~DataBaseController(){
  sqlite3_close(db_);
  for (int i = 0; i < num_tables_; i++){
    free(tables_name_[i]);
  }
  free(tables_name_);
  DestroyTable(actual_table_);
  DestroyTable(query_table_);
  free(err_msg_);
  //free(actual_pos_ref_);
}

DataBaseController& DataBaseController::Instance(){
  static DataBaseController db_controller;
  return db_controller;
};

void DataBaseController::SetActualTable(Table *table){
  actual_table_ = table;
}

int GetNumTables(void *notused,int num_colums, char **data, char **colum_name){
  int *num_tables = (int *) notused;
  printf("Total de tablas-> %s\n",data[0]);
  *num_tables = atoi(data[0]);
  return 0;
}

int CallbackGetTotalColumns(void *_cols,int num_columns, char **data, char **colum_name){
  int *cols = (int*) _cols;
  *cols = num_columns;  

  return 0;
}

int CallbackInsertRows(void *table_,int num_columns, char **data, char **colum_name){
  Table **table = (Table**) table_;
  InsertRow(*table,data);
  InsertColNames(*table,colum_name);
  return 0;
}

bool DataBaseController::OpenDB(char *name){

  if(sqlite3_open_v2(name,&db_,SQLITE_OPEN_READONLY,NULL) == SQLITE_OK && !db_opened_){
    sqlite3_close(db_);
    sqlite3_open(name,&db_);

    // Get total tables
    sqlite3_exec(db_, "SELECT COUNT(name) FROM sqlite_master WHERE (type = 'table' AND name != 'sqlite_sequence' AND name != 'sqlite_stat1')",
                                              GetNumTables, &num_tables_, &err_msg_);
    tables_name_ = (char**) malloc(sizeof(char*) * (num_tables_));
    for(int i = 0; i < num_tables_; i++){
        tables_name_[i] = (char*) malloc(sizeof(char) * 50);
    }
    
    sqlite3_exec(db_,"SELECT name FROM sqlite_master WHERE (type = 'table' AND name != 'sqlite_sequence' AND name != 'sqlite_stat1')",
                                        CallbackGetTablesName, tables_name_,&err_msg_);
    GetTablesName();

    db_opened_ = true;
    table_selected_ = false;
    return true;
  }

  return false;
}

void DataBaseController::MainWindow(){
  static bool open_popup = false;
  static bool open_error_popup = false;
  static bool open_file_explorer = false;

  ImGuiWindowFlags flags = ImGuiWindowFlags_::ImGuiWindowFlags_None;
  flags |= ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar;
  
  if(!ImGui::Begin("DB Viewer", NULL,flags)){

    
    ImGui::End();
    return;
  }

  // Menu db options
  if(ImGui::BeginMenuBar()){
    if(ImGui::BeginMenu("Options")){
      if(ImGui::MenuItem("Open","O")){
        open_popup = true;
        open_error_popup = false;
        open_file_explorer = true;
      }
      if(ImGui::MenuItem("Close")){
        //open_popup = true;
        //open_error_popup = false;
        //open_file_explorer = true;
        
        CloseDB();
      }

      ImGui::EndMenu();
    }

    ImGui::EndMenuBar();
  }


  // Pop up open data base
  if(open_popup){
    open_popup = false;
    open_file_explorer = false;
    ImGui::OpenPopup("Select DB");

    //Open file explorer
    nfdchar_t *outPath = NULL;
    nfdresult_t result = NFD_OpenDialog( NULL, NULL, &outPath );
    if ( result == NFD_OKAY ) {
        puts(outPath);
        strcpy(db_name_,outPath);
        free(outPath);
    }
    else if ( result == NFD_CANCEL ) {
        puts("User pressed cancel.");
    }
    else {
        printf("Error: %s\n", NFD_GetError() );
    }
    

  }
  ImVec2 center;
  center.x = ImGui::GetWindowPos().x + (ImGui::GetWindowSize().x / 2);
  center.y = ImGui::GetWindowPos().y + (ImGui::GetWindowSize().y / 2);
  ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
  if(ImGui::BeginPopupModal("Select DB", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
    ImGui::Text("Open database\nWrite the path from the .exe file to hte database.\nMake sure write the extension of the file.");
    ImGui::Separator();
    ImGui::PushItemWidth(500);
    if(ImGui::InputText("##db_name",db_name_,500, ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue) || ImGui::Button("Acept")){

      // Controll errors
      if(strlen(db_name_) > 0){
        if(OpenDB(db_name_)){
          memset(db_name_,'\0',50);
          ImGui::CloseCurrentPopup();
        }else{
          // La bd ya está abierta
          open_error_popup = true;
        }
      }else{
        // El input esta vacio
        open_error_popup = true;
      }
      
    }
    ImGui::SameLine();
    if(ImGui::Button("Close")){
        ImGui::CloseCurrentPopup();
    }

    // Error messages
    if(open_error_popup){
      if (db_opened_) {
        ImGui::TextColored({255, 0, 0, 255}, "Can't open the database. \nDatabase already open. Close the database to open another.");
      } else {
        ImGui::TextColored({255, 0, 0, 255}, "Can't open the database. \nMake sure the path from the .exe file to the database is correct.");
      }
    }
    ImGui::EndPopup();
  }
  // End open data base


  TablesNameWindow();
  ShowTable();
  PreviewWindow();
  QueryWindow();

  ImGui::End();
}

void DataBaseController::QueryWindow(){
  ImVec2 vec = {0.0f,0.0f}; // 0 es para que ocupe el 100% del contenedor
  
  if(!ImGui::BeginChild("Query",vec,true)){
    
    ImGui::EndChild();
    return;
  }
  HelpMarker("SQL Sentence");
  //ImGui::Text("SQL Sentence");
  ImGuiInputTextFlags flags = ImGuiInputTextFlags_::ImGuiInputTextFlags_None;
  //flags |= ImGuiInputTextFlags_EnterReturnsTrue;
  flags |= ImGuiInputTextFlags_AllowTabInput;

  static bool bol_aux = false;
  if(!bol_aux)strcat(query_,"SELECT * FROM albums");
  bol_aux = true;
  
  char query_aux[500];

  

  ImGui::InputTextMultiline("##sentece",query_,500,ImVec2(ImGui::GetWindowSize().x,0.0f),flags);
  if(ImGui::Button("Execute") && db_opened_){
    // execute user's query
    DestroyTable(query_table_);
    query_table_ = nullptr;
    strcpy(query_aux,query_);
    strcat(query_aux," LIMIT 1\n");

    int *numcols_tmp = new int;
    sqlite3_exec(db_,query_,CallbackGetTotalColumns,numcols_tmp,&error_message_);

    //Check is is a SELECT query
    char *check_select = (char*) malloc(sizeof(char)*7);
    snprintf(check_select,7,"%s",query_);
    strupr(check_select);

    if(strcmp(check_select,"SELECT") == 0 && !error_message_){
      CreateTable(&query_table_, *numcols_tmp,120);
      sqlite3_exec(db_,query_,CallbackInsertRows,&query_table_,&error_message_);
    }



    strncpy(query_aux_,query_,501);
    //memset(query_,'\0',501);
    SetTableCreated(false);
    delete numcols_tmp;
  }
  ImGui::EndChild();
}

void DeleteRow(char *table_name,char *colum_name, char *id, sqlite3* db){
  char query[100] = {"DELETE FROM "};
  strcat(query,table_name);
  strcat(query," WHERE ");
  strcat(query,colum_name);
  strcat(query," = ");
  strcat(query,id);
  printf("Query-> %s\n",query);
  sqlite3_exec(db,query,nullptr,nullptr,nullptr);

}

int CallbackPreviewTable(Table *table,void *data_base, int num_colums, char **data, char **col_name){
  
  DataBaseController& db_controller = DataBaseController::Instance();
  
  char table_name[30];
  strcpy(table_name,GetTableName(table)?GetTableName(table):"NULL");
  sqlite3* db = (sqlite3*) data_base;
  
  ImGui::TableNextRow();  
  for(int i = 0; i < num_colums; i++){
    ImGui::TableSetColumnIndex(i);
    char tmp[120];
    snprintf(tmp,120,"##%d",rand()%200);
    strcat(tmp,col_name[i]);
    strcat(tmp,data[i]);

    //printf("---- %s -----\n",tmp);
    //if(ImGui::InputText(tmp,data[i],70,ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue)){
    ImGui::Text(data[i]);
      // Update de la row
      // Mostrar pop up-> ¿Desea actualizar la tabla? -> Tabla actualizada, Error actuaizando
    //} 
  }

    //Pintar basura
    
    if(db_controller.actual_table_ == table){

      // Columna Delete & Edit

      ImGui::TableSetColumnIndex(num_colums);
      ImGui::Button("Delete");
      if(ImGui::IsItemClicked()){
        //IsMouseDoubleClicked
        //Delete row
        DeleteRow(table_name,col_name[0],data[0],db);
        db_controller.SetTableCreated(false);
      }
  

      ImGui::SameLine();
      ImGui::Button("Edit");
      if(ImGui::IsItemClicked()){
        db_controller.edit_popup_open_ = true;
        db_controller.row_data_ = data;

        int cols_num = GetColumnsNumber(db_controller.actual_table_);
        for(int i = 0; i < cols_num; i++){
          snprintf(db_controller.row_data_copy_[i],120,"%s",data[i]);
        }

      }
    }

  return 0;
} 

void DataBaseController::PreviewWindow(){

  ImGuiTableFlags table_flags = ImGuiTableFlags_::ImGuiTableFlags_None;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_RowBg;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_Borders;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersH;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersOuterH;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersInnerH;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersV;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersOuterV;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersInnerV;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersOuter;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_BordersInner;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_Resizable;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_ScrollX;
  table_flags |= ImGuiTableFlags_::ImGuiTableFlags_ScrollY;
  
  ImVec2 size = {0,0};
  size.x = 0;
  size.y = ImGui::GetWindowSize().y * 2.0f/3.0f;
  ImGui::SameLine();
  if(!ImGui::BeginChild("Table content",size,true)){
    ImGui::EndChild();
    return;
  }
  if (ImGui::BeginTabBar("ViewerTabs")) {
    if (ImGui::BeginTabItem("Data")) {
      if (table_selected_) {
        if(table_created_){
          // Callback to print data table
          int num_columns = GetColumnsNumber(actual_table_);
          char **col_names = GetColumnsNames(actual_table_);


          if(ImGui::BeginTable("##Table_content",num_columns+1,table_flags,ImVec2((1.175494351e-38F),0))){

            for(int i = 0; i<num_columns; i++){
              ImGui::TableSetupColumn(col_names[i]);
            }
            ImGui::TableSetupColumn("");
            ImGui::TableHeadersRow();
            RunTable(actual_table_,CallbackPreviewTable, db_);

            ImGui::EndTable();
          }
        }
      }

      // Edit Row popup
      if (edit_popup_open_ == true) {
        printf("edit_popup_open_ == true\n");
        ImGui::OpenPopup("Edit Row");
        edit_popup_open_ = false;
      }
      ImVec2 center;
      center.x = ImGui::GetWindowPos().x + (ImGui::GetWindowSize().x / 2);
      center.y = ImGui::GetWindowPos().y + (ImGui::GetWindowSize().y / 2);
      ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

      //Pop up data
      if(ImGui::BeginPopupModal("Edit Row", NULL)){
        ImGui::Text(GetTableName(actual_table_));
        int num_columns = GetColumnsNumber(actual_table_);
        char **colum_names = GetColumnsNames(actual_table_);
        if(ImGui::BeginTable(GetTableName(actual_table_),num_columns)){

          // Set Colum names
          for(int i = 0; i<num_columns; i++){
            ImGui::TableSetupColumn(colum_names[i]);
          }
          ImGui::TableHeadersRow();
          ImGui::TableNextRow();
          // Set data in columns
          for (int i = 0; i < num_columns; i++){
            ImGui::TableSetColumnIndex(i);
            char label[40] = {"##Rowdata"};
            snprintf(label,120,"##%s",colum_names[i]);

            ImGui::InputText(label,row_data_copy_[i],120);
          }
          ImGui::TableNextRow();
          ImGui::TableSetColumnIndex(0);
          ImGui::Separator();
          if(ImGui::Button("Save")){
            // Update en la DB
            char query[300];
            snprintf(query,120,"%s%s%s","UPDATE ",GetTableName(actual_table_), " SET ");
            for(int i = 0; i<num_columns;i++){
              strncat(query,colum_names[i], 300);
              strncat(query," = ", 300);
              strncat(query,"'", 300);
              strncat(query,row_data_copy_[i], 300);
              strncat(query,"'", 300);
              if(i<num_columns-1)strncat(query,", ", 300);
            }

            // Condicion where del update
            strncat(query," WHERE ", 300);
            for (int i = 0; i < num_columns; i++){
              strncat(query,colum_names[i], 300);
              strncat(query," = ", 300);
              strncat(query,"'", 300);
              strncat(query,row_data_[i], 300);
              strncat(query,"'", 300);
              if(i<num_columns-1)strncat(query, " AND ", 300);
            }

            //printf("%s\n",query);
            sqlite3_exec(db_,query,nullptr,nullptr,&err_msg_);
            ImGui::CloseCurrentPopup();
            SetTableCreated(false);

            //printf("%s\n",err_msg_);
          }

          ImGui::SameLine();
          if(ImGui::Button("Close")){
            ImGui::CloseCurrentPopup();
          }
          

          ImGui::EndTable();
        }


        ImGui::EndPopup();
      }
      ImGui::EndTabItem();
    }
    if (ImGui::BeginTabItem("SQL")) {
      //Preview of SQL Query window
      if(error_message_){
        ImGui::TextColored(ImVec4(255,0,0,255),"[ERROR]");
        ImGui::SameLine();
        ImGui::Text(error_message_);
      } else {
        if(strlen(query_aux_)>0){
          ImGui::TextColored(ImVec4(0,255,0,255),"[OK]");
          ImGui::SameLine();
          ImGui::Text(query_aux_);
        }else{
          ImGui::TextColored(ImVec4(238/255.0f,210/255.0f,2/255.0f,255),"[EMPTY]");
        }
      }
      if(query_table_ != nullptr){

        ImGui::Separator();
        //Show query table
        int num_query_columns = GetColumnsNumber(query_table_);

        if(ImGui::BeginTable("##QueryContent", num_query_columns, table_flags,ImVec2((1.175494351e-38F),0))){
          char **col_names = GetColumnsNames(query_table_);
          for (int i = 0; i < num_query_columns; i++){
            ImGui::TableSetupColumn(col_names[i]);
          }
          ImGui::TableHeadersRow();
          RunTable(query_table_,CallbackPreviewTable, db_);
          
          ImGui::EndTable();
        }
      }
      ImGui::EndTabItem();
    }
    ImGui::EndTabBar();
  }
  ImGui::EndChild();


}

void DataBaseController::ShowTable(){

  if(table_selected_ && !table_created_){
    // Reset de la tabla pa meter la nueva
    if(actual_table_ != nullptr)DestroyTable(actual_table_);
    char *err_msg;

    //Create table with num columns
    char query_rows_columns[50] = {"SELECT * FROM "};
    strcat(query_rows_columns,current_table_);
    strcat(query_rows_columns," LIMIT 1");

    int *num_cols_aux = new int;
    sqlite3_exec(db_,query_rows_columns,CallbackGetTotalColumns,num_cols_aux,&err_msg);
    CreateTable(&actual_table_, *num_cols_aux,120);
    SetTableName(actual_table_,current_table_);
    
    delete num_cols_aux;

    // Insert row data
    char query_data[50] = "SELECT * FROM ";
    strcat(query_data,current_table_);
    sqlite3_exec(db_,query_data,CallbackInsertRows,&actual_table_, &err_msg);

    table_created_ = true;

  }
}

void DataBaseController::TablesNameWindow(){
  ImVec2 size = {0,0};
  size.x = ImGui::GetWindowSize().x * 1.0f/3.0f;
  size.y = ImGui::GetWindowSize().y * 2.0f/3.0f;
  if(size.x > 215.0f)size.x = 215.0f;
  if(!ImGui::BeginChild("Tables",size,true)){
    ImGui::EndChild();
    return;
  }
  ImGui::Text("TABLAS");

  for(int i = 0; i < num_tables_; i++){
    if(ImGui::SmallButton(tables_name_[i])){
      table_selected_ = true;
      table_created_ = false;
      strcpy(current_table_,tables_name_[i]);
    }
    ImGui::Separator();
  }

  ImGui::EndChild();
}

void DataBaseController::GetTablesName(){
  printf("----- Nombre de las tablas -----\n");
  for(int i = 0; i < num_tables_; i++){
    printf("%d-> %s\n",i,tables_name_[i]);
  }
}

void DataBaseController::SetTableCreated(bool state){
  table_created_ = state;
}

void DataBaseController::CloseDB(){

  DestroyTable(actual_table_);
  DestroyTable(query_table_);
  actual_table_ = nullptr;
  query_table_ = nullptr;
  free(tables_name_);
  num_tables_ = 0;
  db_opened_ = false;
  sqlite3_close(db_);
}
