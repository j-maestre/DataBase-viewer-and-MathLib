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
  /**
   * @brief Create ImGui Row in table for every row in the table selected
   * 
   * @param table Table selected
   * @param data_base sqlite3 database instance
   * @param num_colums Number of columns of the table
   * @param data Data of every column
   * @param col_name Name of the colum
   * @return int 
   */
  friend int CallbackPreviewTable(Table *table,void *data_base, int num_colums, char **data, char **col_name);

  /**
   * @brief Callback to set the type of the data of every column in the tabe selected
   * 
   * @param types_ Pointer to save the types
   * @param num_columns Number of columns
   * @param data Type of the data
   * @param colum_name Name of the column
   * @return int 
   */
  friend int CallbackInsertColumnsDataType(void *types_,int num_columns, char **data, char **colum_name);

  /**
   * @brief Callabck to save the names of all tables in database
   * 
   * @param names Double pointer to save the names 
   * @param num_colums Number of columns
   * @param data Data who contains the names of the columns
   * @param colum_name Name of colum
   * @return int 
   */
  friend int CallbackGetTablesName(void *names,int num_colums, char **data, char **colum_name);

  /**
   * @brief Static instance of the class 
   * 
   * @return DataBaseController& 
   */
  static DataBaseController& Instance();

  // Constructor de copia
  /**
   * @brief Construct a new Data Base Controller object
   * 
   */
  DataBaseController(const DataBaseController&) = delete; // Palabra clave, para decirle que no exista ese constructor. Tambien se puede poner default en vez de delete para que lo haga el compilador por defecto

  /**
   * @brief Destroy the Data Base Controller object
   * 
   */
  ~DataBaseController(); // Destructor

  /**
   * @brief 
   * 
   */
  void operator = (const DataBaseController&) = delete; // Sobre carga de operador para la clase

    /**
   * @brief Open main window with all subpages
   * 
   */
  void MainWindow();

  /**
   * @brief This function opens the database, save the number of tables in database and the names
   * 
   * @param name Name of database file
   * @return true if can open the db
   * @return false if can't open the db
   */
  bool OpenDB(char *name);
  
  /**
   * @brief Close the database and resets all the variables used
   * 
   */
  void CloseDB();

 private:
  // Private functions
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
  bool edit_popup_open_;

  unsigned int pagination;

  char **row_data_;
  char **row_data_copy_;
  unsigned int max_colums;
  unsigned int col_offset;

  char query_[501];
  char query_aux_[501];

  sqlite3* db_;

  /**
   * @brief View of the user's query and execute it
   * 
   */
  void QueryWindow();
  

  /**
   * @brief Construct a new Data Base Controller object
   * 
   */
  DataBaseController();

  /**
   * @brief When select a table, this function get the number of columns, the name of the columns, the type of data columns and set the necesaries values to show it 
   * 
   */
  void ShowTable();


  /**
   * @brief Select table window
   * 
   */
  void TablesNameWindow();
  /**
   * @brief Shows content of table or the result of user's query
   * 
   */
  void PreviewWindow();

};


#endif