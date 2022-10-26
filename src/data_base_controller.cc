#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esat_extra/imgui.h>
#include "data_base_controller.h"
#include "table.h"
#include "nfd.h"

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
  CallbackGetTablesName(&actual_pos_ref_,0,nullptr,nullptr);
}

DataBaseController::~DataBaseController(){
  sqlite3_close(db_);
  for (int i = 0; i < num_tables_; i++){
    free(tables_name_[i]);
  }
  free(tables_name_);
  DestroyTable(actual_table_);
  free(err_msg_);
  free(actual_pos_ref_);
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

int CallbackGetTableColums(void *table_to_insert,int num_colums, char **data, char **colum_name){

  //Insert col names
  Table *table = (Table*) table_to_insert;
  printf("Colum name-> %s Data-> %s\n",colum_name[0], data[0]);
  InsertColNames(table, colum_name);

  printf("Columnas insertadas\n");
  return 0; 
}

int CallbackGetTable(void *table_to_insert,int num_colums, char **data, char **colum_name){

  // Aqui iremos metiendo la info en la Table creada
  Table *table = (Table*) table_to_insert;
  //printf("----- COLUMNS-> %d -----\n",num_colums);
  //printf("Colum name-> %s Data-> %s\n",colum_name[0], data[0]);
  //CreateTeable(&table,num_colums,80);
  
  //InsertRow(table,data);
  //InsertRow(table,llamar a "GetIndex",data);
  //NextRow(table);
  printf("Fila insertada\n");

  return 0; 
}

int CallbackGetTotalRows(void *_cols,int num_columns, char **data, char **colum_name){
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

int CallbackSaveTable(void *table_,int num_colums, char **data, char **colum_name){
  // Aqui entra una vez por cada fila
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

void DataBaseController::ExecuteSelect(char *query){
  char *errmsg;
  sqlite3_exec(db_,query,CallbackGetTable,nullptr,&errmsg);
}

void DataBaseController::ShowWindow(){
  /*printf("------------------------------------------\n");
  printf("actual_pos_ref_ -> %d [%p]\n", *actual_pos_ref_, actual_pos_ref_); // esta petando aqui
  printf("------------------------------------------\n");*/
  MainWindow();
}

void DataBaseController::MainWindow(){
  static bool open_popup = false;
  static bool open_error_popup = false;
  static bool open_file_explorer = false;

  ImGuiWindowFlags flags = ImGuiWindowFlags_::ImGuiWindowFlags_None;
  flags |= ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar;
  flags |= ImGuiWindowFlags_::ImGuiWindowFlags_NoMove;
  
  if(!ImGui::Begin("DB Viewer", NULL,flags)){

    
    ImGui::End();
    return;
  }

  // Menu db options
  if(ImGui::BeginMenuBar()){
    if(ImGui::BeginMenu("Options")){
      if(ImGui::MenuItem("Open","Ctrl+O")){
        open_popup = true;
        open_error_popup = false;
        open_file_explorer = true;
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

  ImGui::End();
}

void DeleteRow(char *table_name,char *colum_name, char *id){
  char query[100] = {"'DELETE FROM "};
  strcat(query,table_name);
  strcat(query," WHERE ");
  strcat(query,colum_name);
  strcat(query," = ");
  strcat(query,id);
  printf("Query-> %s\n",query);


}

int CallbackPreviewTable(Table *table,void *current_table, int num_colums, char **data, char **col_name){
  char *table_name = (char*) current_table;
  
  
  ImGui::TableNextRow();  
  for(int i = 0; i < num_colums; i++){
    ImGui::TableSetColumnIndex(i);
    //static char data_2[70] = {"Row columna 1\0"};
    //printf("ROW DATA-> colname: %s, data: %s\n",col_name[i],data[i]);

    //if(ImGui::InputText("##data",data[i],70,ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue)){
    if(ImGui::InputText("##data",data[i],70,ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue)){
      // Update de la row
      // Mostrar pop up-> ¿Desea actualizar la tabla? -> Tabla actualizada, Error actuaizando
    } 
  }

  //Pintar basura
    ImGui::TableSetColumnIndex(num_colums);
    if(ImGui::ColorButton("Delete row", ImVec4(255,0,0,0),ImGuiColorEditFlags_::ImGuiColorEditFlags_NoTooltip)){
      //Delete row
      DeleteRow(table_name,col_name[0],data[0]);
    }
    if(ImGui::IsItemHovered()){
      ImGui::SameLine();
      ImGui::TextColored(ImVec4(255,0,0,255),"Delete row");
      
      // no va
      //ImGui::SetMouseCursor(ImGuiMouseCursor_::ImGuiMouseCursor_Hand);
    }
    //ImGui::ImageButton("../data/trash.png",ImVec2(30,30));

  return 0;
} 

void DataBaseController::PreviewWindow(){
  
  ImVec2 size = {0,0};
  size.x = 0;
  size.y = ImGui::GetWindowSize().y * 2.0f/3.0f;
  ImGui::SameLine();
  if(!ImGui::BeginChild("Table content",size,true)){
    ImGui::EndChild();
    return;
  }
  if(table_created_){
      // Callback to print data table
      int num_columns = GetColumnsNumber(actual_table_);
      char **col_names = GetColumnsNames(actual_table_);
      /*printf("Num columns-> %d\n",num_columns);
      printf("Colum 0 name-> %s\n",col_names[0]);*/

      if(ImGui::BeginTable("##Table_content",num_columns+1)){

        for(int i = 0; i<num_columns; i++){
          ImGui::TableSetupColumn(col_names[i]);
        }
        ImGui::TableSetupColumn("");
        ImGui::TableHeadersRow();
        RunTable(actual_table_,CallbackPreviewTable, current_table_);

        ImGui::EndTable();
      }

    }

  ImGui::EndChild();


}

void DataBaseController::ShowTable(){

  if(table_selected_ && !table_created_){
    // Reset de la tabla pa meter la nueva
    if(actual_table_ != nullptr)DestroyTable(actual_table_);
    char *err_msg;

    printf("\nSHOW TABLE\n");

    //Create table with num columns
    char query_rows_columns[50] = {"SELECT * FROM "};
    strcat(query_rows_columns,current_table_);
    strcat(query_rows_columns," LIMIT 1");

    int *num_cols_aux = new int;
    sqlite3_exec(db_,query_rows_columns,CallbackGetTotalRows,num_cols_aux,&err_msg);
    CreateTeable(&actual_table_, *num_cols_aux,120);
    
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

Table* DataBaseController::GetActualTable(){
  return actual_table_;
}
