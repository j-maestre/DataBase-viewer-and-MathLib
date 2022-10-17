#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esat_extra/imgui.h>
#include "data_base_controller.h"

DataBaseController::DataBaseController(){
  db_opened_ = false;
}
DataBaseController::~DataBaseController(){}

DataBaseController& DataBaseController::Instance(){
  static DataBaseController db_controller;
  return db_controller;
};

int GetNumTables(void *notused,int num_colums, char **data, char **colum_name){
  int *num_tables = (int *) notused;
  printf("Total de tablas-> %s\n",data[0]);
  *num_tables = atoi(data[0]);
  return 0;
}

int CallbackGetTablesName(void *notused,int num_colums, char **data, char **colum_name){
  static int actual_pos = 0;
  char **tables_name = (char **) notused;
  for(int i=0; i < num_colums; i++){
    strcpy(tables_name[actual_pos], data[i]);
    actual_pos++;
  }
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
    return true;
  }

  return false;
}

void DataBaseController::ExecuteSelect(char *query){
  char *errmsg;
  sqlite3_exec(db_,query,CallbackGetTablesName,nullptr,&errmsg);
}



void DataBaseController::ShowWindow(){
  MainWindow();
}

void DataBaseController::MainWindow(){
  static bool open_popup = false;
  static bool open_error_popup = false;

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
      if(ImGui::MenuItem("Open")){
        open_popup = true;
        open_error_popup = false;
      }

      ImGui::EndMenu();
    }

    ImGui::EndMenuBar();
  }


  // Pop up open data base
  if(open_popup){
    open_popup = false;
    ImGui::OpenPopup("Select DB");
  }
  if(ImGui::BeginPopupModal("Select DB", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
    ImGui::Text("Data Base name");

    if(ImGui::InputText("##db_name",db_name_,50, ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue) || ImGui::Button("Acept")){

      // Controll errors
      if(strlen(db_name_) > 0){
        if(OpenDB(db_name_)){
          memset(db_name_,'\0',50);
          ImGui::CloseCurrentPopup();
        }else{
          open_error_popup = true;
        }
      }else{
        //La bd ya está abierta
        open_error_popup = true;
      }
      
    }
    ImGui::SameLine();
    if(ImGui::Button("Close")){
        ImGui::CloseCurrentPopup();
    }

    // Error messages
    if(open_error_popup){
      db_opened_ ?ImGui::Text("Data base is opened!"):ImGui::Text("Data base no found!");
    }
    ImGui::EndPopup();
  }
  // End open data base






  TablesNameWindow();

  ImGui::End();
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



  ImGui::EndChild();
}


void DataBaseController::GetTablesName(){
  printf("----- Nombre de las tablas -----\n");
  for(int i = 0; i < num_tables_; i++){
    printf("%d-> %s\n",i,tables_name_[i]);
  }
}