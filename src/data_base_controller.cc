#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esat_extra/imgui.h>
#include "data_base_controller.h"

DataBaseController::DataBaseController(){}
DataBaseController::~DataBaseController(){}

DataBaseController& DataBaseController::Instance(){
  static DataBaseController db_controller;
  return db_controller;
};

int GetNumTables(void *notused,int num_colums, char **data, char **colum_name){
  DataBaseController* db_ptr = (DataBaseController*) notused;
  printf("Total de tablas-> %s\n",data[0]);
  db_ptr->SetNumTables(atoi(data[0]));
  return 0;
}

int CallbackGetTablesName(void *notused,int num_colums, char **data, char **colum_name){
  DataBaseController* db_ptr = (DataBaseController*) notused;
  static int actual_pos = 0;
  // Guardar el nombre de las tablas
  for(int i=0; i < num_colums; i++){
    db_ptr->SetTableName(actual_pos,data[i]);
    //printf("Nombre tabla %d -> %s\n",actual_pos, data[i]);
    actual_pos++;
  }
  return 0;
}


bool DataBaseController::OpenDB(char *name){
  if(sqlite3_open_v2(name,&db_,SQLITE_OPEN_READONLY,NULL) == SQLITE_OK){
    sqlite3_close(db_);
    sqlite3_open(name,&db_);

    // Get total tables
    sqlite3_exec(db_,"SELECT COUNT(name) FROM sqlite_master WHERE type = 'table'",GetNumTables,this,&err_msg_);
    tables_name_ = (char**) malloc(sizeof(char*) * (num_tables_));
    for(int i = 0; i < num_tables_; i++){
        tables_name_[i] = (char*) malloc(sizeof(char) * 50);
    }
    
    sqlite3_exec(db_,"SELECT name FROM sqlite_master WHERE type = 'table'",CallbackGetTablesName,this,&err_msg_);
    GetTablesName();


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
  ImGuiWindowFlags flags = ImGuiWindowFlags_::ImGuiWindowFlags_None;
  flags |= ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar;
  flags |= ImGuiWindowFlags_::ImGuiWindowFlags_NoMove;
  
  if(!ImGui::Begin("DB Viewer", NULL,flags)){
    ImGui::End();
    return;
  }
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


// Setters
void DataBaseController::SetNumTables(int num){
  num_tables_ = num;
}

void DataBaseController::SetTableName(int pos, char *name){
  //printf("Guardando en %d la tabla %s\n",pos,name);
  strcpy(tables_name_[pos], name);
}


void DataBaseController::GetTablesName(){
  printf("----- Nombre de las tablas -----\n");
  for(int i = 0; i < num_tables_; i++){
    printf("%d-> %s\n",i,tables_name_[i]);
  }
}