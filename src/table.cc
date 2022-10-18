#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"


struct Table {
  int cols, rows;
  int curr_row;
  char ***data_table;
  char **col_names;
};

int CreateTeable(Table **table, int col_num, int row_num) {
  *table = (Table*)malloc(sizeof(table));
  (*table)->cols = col_num;
  (*table)->rows = row_num;
  (*table)->curr_row = 0;
  (*table)->data_table = (char ***) malloc(sizeof(char **) * row_num);
  for (int i = 0; i < row_num; i++) {
    (*table)->data_table[i] = (char **) malloc(sizeof(char *) * col_num);
    for (int j = 0; j < col_num; j++){
      *(*((*table)->data_table + i) + j) = nullptr;
    }
  }
  (*table)->col_names = (char **) malloc(sizeof(char *) * col_num);
  for (int i = 0; i < col_num; i++) {
    (*table)->col_names[i] = nullptr;
  }
  return 0;
}

void InsertColNames(Table *table, char **col_names) {
  for (int i = 0; i < table->cols; i++) {
    printf("Strlen %d: %d\n", i, strlen(col_names[i]));
    if (table->col_names[i] == nullptr) {
      table->col_names[i] = (char *) malloc(sizeof(char) * strlen(col_names[i]));
    } else if (strlen(col_names[i]) != strlen(table->col_names[i])) {
      table->col_names[i] = (char *) realloc(
                        table->col_names[i], 
                        sizeof(char) * strlen(col_names[i]));
    }
    memset(table->col_names[i], '\0', strlen(col_names[i]));
    strcpy(table->col_names[i], col_names[i]);
  }
}

int InsertRow(Table *table, char**row_data) {
  for (int i = 0; i < table->cols; i++) {
    if (*(*(table->data_table + table->curr_row) + i) == nullptr) {
      *(*(table->data_table + table->curr_row) + i) = (char *) malloc(
                    sizeof(char) * strlen(row_data[i] ? row_data[i] : "NULL"));
    } else if (strlen(row_data[i] ? row_data[i] : "NULL") != strlen(
                        *(*(table->data_table + table->curr_row) + i))) {
      *(*(table->data_table + table->curr_row) + i) = (char *) realloc(
                                        *(*(table->data_table + table->curr_row) + i), 
                sizeof(char) * strlen(row_data[i] ? row_data[i] : "NULL"));
    }
    memset(*(*(table->data_table + table->curr_row) + i), '\0', 
            strlen(row_data[i]));
    strcpy(*(*(table->data_table + table->curr_row) + i),
            row_data[i] ? row_data[i] : "NULL");
  }
  return 0;
}

void NextRow(Table *table) {
  table->curr_row++;
  table->curr_row %= table->rows;
}

int RunTable(Table *table, int (*callback)(void *, int, char **, char **), void *user_data) {
  int state = 0;
  for (int i = 0; i < table->rows; i++) {
    state = callback(user_data, table->cols, table->data_table[i], table->col_names);
  }
  return state;
}

void DestroyTable(Table *table) {
  for (int i = 0; i < table->rows; i++) {
    for (int j = 0; i < table->cols; j++) {
      if (*(*(table->data_table + i) + j) != nullptr) {
        free(*(*(table->data_table + i) + j));
      }
    }
  }
  for (int i = 0; i < table->rows; i++) {
    if (*(table->data_table + i) != nullptr) {
      free(*(table->data_table + i));
    }
  }
  for (int i = 0; i < table->cols; i++) {
    if ((table->col_names + i) != nullptr) {
      free((table->col_names + i));
    }
  }
  if (table->col_names != nullptr) {
    free(table->col_names);
  }
  if (table->data_table != nullptr) {
    free(table->data_table);
  }
  if (table != nullptr) {
    free(table);
  }
  table = nullptr;
}