/**
 * @file data_base_controller.h
 * @author Xema Maestre <maestrequi@esat-alumni.com>
 * @author Hector Ochando <ochandoca@esat-alumni.com>
 * @brief 
 * 
 */


#ifndef __DATA_BASE_CONTROLLER_H__ 
#define __DATA_BASE_CONTROLLER_H__ 1 

#include <esat_extra/sqlite3.h>
#include "table.h"

class DataBaseController{
 public:
  // Public functions
  friend int CallbackPreviewTable(Table *table,void *data_base, int num_colums, char **data, char **col_name);
  friend int CallbackInsertColumnsDataType(void *types_,int num_columns, char **data, char **colum_name);
  friend int CallbackGetTablesName(void *notused,int num_colums, char **data, char **colum_name);
  static DataBaseController& Instance();

  //** Importante **
  // Constructor de copia
  DataBaseController(const DataBaseController&) = delete; // Palabra clave, para decirle que no exista ese constructor. Tambien se puede poner default en vez de delete para que lo haga el compilador por defecto

  ~DataBaseController(); // Destructor

  void operator = (const DataBaseController&) = delete; // Sobre carga de operador para la clase

    /**
   * @brief Open main window with all subpages
   * 
   */
  void MainWindow();
  bool OpenDB(char *name);
  void GetTablesName();
  void SetActualTable(Table *);
  void SetTableCreated(bool state);
  void CloseDB();
  Table* GetActualTable();

 private:
  // Private functions
  sqlite3* db_;
  int num_tables_;
  char **tables_name_;
  char *err_msg_;
  int actual_pos_; 
  
  bool db_opened_;
  char db_name_[500];
  char current_table_[20];
  bool table_selected_;

  Table *actual_table_; // 20 bytes
  Table *query_table_;
  
  bool table_created_;
  bool cols_name_inserted_;

  char *error_message_;
  char query_[501];
  char query_aux_[501];

  unsigned int pagination;
  bool edit_popup_open_;

  // edit row data
  char **row_data_;
  char **row_data_copy_;
  unsigned int max_colums;
  unsigned int col_offset;

  void QueryWindow();
  

  /**
   * @brief Construct a new Data Base Controller object
   * 
   */
  DataBaseController();

  void ShowTable();
  /**
   * @brief Execute Select query
   * 
   * @param query Select query
   */
  void ExecuteSelect(char *query); // Devolverá una tabla

  /**
   * @brief Execute any type of Query
   * 
   * @param query SQL query
   */
  void ExecuteQuery(char *query);


  /**
   * @brief Select table window
   * 
   */
  void TablesNameWindow();
  /**
   * @brief Shows content of table
   * 
   */
  void PreviewWindow();

  /**
   * @brief execute user's query
   * 
   */
  void SQLWindow();



};


#endif