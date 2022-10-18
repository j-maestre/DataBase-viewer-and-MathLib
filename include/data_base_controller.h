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
  
  static DataBaseController& Instance();

  //** Importante **
  // Constructor de copia
  DataBaseController(const DataBaseController&) = delete; // Palabra clave, para decirle que no exista ese constructor. Tambien se puede poner default en vez de delete para que lo haga el compilador por defecto

  ~DataBaseController(); // Destructor

  void operator = (const DataBaseController&) = delete; // Sobre carga de operador para la clase

  void ShowWindow();
  bool OpenDB(char *name);
  void GetTablesName();
  void SetActualTable(Table *);
  Table* GetActualTable();

 private:
  // Private functions
  sqlite3* db_;
  char **tables_name_;
  int num_tables_;
  char *err_msg_;
  bool db_opened_;
  char db_name_[50];
  char current_table_[20];
  bool table_selected_;
  bool table_created_;
  Table *actual_table_;
  bool cols_name_inserted_;
  int* actual_pos_ref_; 

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
   * @brief Open main window with all subpages
   * 
   */
  void MainWindow();
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