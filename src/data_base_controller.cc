

#include "data_base_controller.h"
#include <stdio.h>

DataBaseController::DataBaseController(){}
DataBaseController::~DataBaseController(){}


int CallbackGetTablesName(void *notused,int num_colums, char **data, char **colum_name){
    for(int i=0; i < num_colums; i++){
        printf("Nombre tabla-> %s\n", data[i]);
    }
    return 0;
}


bool DataBaseController::OpenDB(char *name){
    if(sqlite3_open_v2(name,&db,SQLITE_OPEN_READONLY,NULL) == SQLITE_OK){
        sqlite3_close(db);
        sqlite3_open(name,&db);
        return true;
    }
    return false;
}

void DataBaseController::ExecuteSelect(char *query){
    const char *tmp= "SELECT name FROM sqlite_master WHERE type = 'table'";
    char *errmsg;
    sqlite3_exec(db,tmp,CallbackGetTablesName,nullptr,&errmsg);

}
void DataBaseController::ShowWindow(){
    ExecuteSelect("");
}

