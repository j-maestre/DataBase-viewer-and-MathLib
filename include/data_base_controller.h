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
  void SetNumTables(int);
  void SetTableName(int, char*);
  void GetTablesName();

 private:
  // Private functions
  sqlite3* db_;
  char **tables_name_;
  int num_tables_;
  char *err_msg_;

  // Constructor
  DataBaseController();

  void ShowTable();
  // Consulta Select
  void ExecuteSelect(char *query); // Devolverá una tabla
  // Cualquier tipo de consulta excepto Select
  void ExecuteQuery(char *query);
  // Ventana principal
  void MainWindow();
  // Zona de eleccion de tabla
  void TablesNameWindow();
  // Mostrar contenido de tabla
  void PreviewWindow();
  // Execute user SQL
  void SQLWindow();


};


#endif