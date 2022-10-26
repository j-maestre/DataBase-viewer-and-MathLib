#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "table.h"


struct Table {
  int cols;
  int data_max_size;
  std::vector<char **> data_table;
  char **col_names;
  char *name_;
};

int CreateTable(Table **table, int col_num, int data_size) {
  *table = new Table;
  (*table)->cols = col_num;
  (*table)->col_names = nullptr;
  (*table)->data_max_size = data_size;
  (*table)->name_ = nullptr;
  return 0;
}

void InsertColNames(Table *table, char **col_names) {
  if (nullptr == table) {
    return;
  }
  if (nullptr == col_names) {
    return;
  }
  if (nullptr !=  table->col_names) {
    return;
  }
  char** aux = (char **)malloc(sizeof(char *) * table->cols);

  for (int i = 0; i < table->cols; i++) {
    aux[i] = (char *)malloc((sizeof(char) * table->data_max_size) + 1);
    strncpy(aux[i], col_names[i], table->data_max_size);
    *(aux[i] + table->data_max_size) = '\0';
  }
  table->col_names = aux;
}

int InsertRow(Table *table, char** row_data) {
  if (nullptr == table) {
    return -1;
  }
  if (nullptr == row_data) {
    return -2;
  }
  char** aux = (char **)malloc(sizeof(char *) * table->cols);
  
  for (int i = 0; i < table->cols; i++) {
    aux[i] = (char *)malloc((sizeof(char) * table->data_max_size) + 1);
    strncpy(aux[i], row_data[i], table->data_max_size);
    *(aux[i] + table->data_max_size) = '\0';
  }
  table->data_table.push_back(aux);
  return 0;
}

int RunTable(Table *table, int (*callback)(Table *, void *, int, char **, char **), void *user_data) {
  if (nullptr == table) {
    return -1;
  }
  int state = 0;

  for (int i = 0; i < table->data_table.size() && 0 == state; i++) {
    state = callback(table, user_data, table->cols, table->data_table[i], table->col_names);
  }

  return state;
}

char** GetColumnsNames(Table *table) {
  if (nullptr == table) {
    return nullptr;
  }
  return table->col_names;
}

int GetColumnsNumber(Table* table) {
  if (nullptr == table) {
    return -1;
  }

  return table->cols;
}

int GetRowsNumber(Table* table) {
  if (nullptr == table) {
    return -1;
  }

  return table->data_table.size();
}

void DestroyTable(Table *table) {
  if (nullptr == table) {
    return;
  }
  
  for (int i = 0; i < table->data_table.size(); i++) {
    for (int j = 0; j < table->cols; j++) {
      free(*((table->data_table[i]) + j));
    }
    free(table->data_table[i]);
  }

  for (int i = 0; i < table->cols; i++) {
    free(table->col_names[i]);
  }
  free(table->col_names);

  delete table;
}

void SetTableName(Table *table, char *name){
  if (nullptr == table) {
    return;
  }
  if (nullptr == name) {
    return;
  }
  if (table->name_ != nullptr) {
    return;
  }
  char *aux = (char *)malloc(sizeof(char) * table->data_max_size + 1);

  strncpy(aux, name, table->data_max_size);
  *(aux + table->data_max_size) = '\0';
  table->name_ = aux;
}

char* GetTableName(Table *table){
  if (nullptr == table) {
    return;
  }
  return table->name_;
}