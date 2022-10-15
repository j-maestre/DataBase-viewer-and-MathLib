/*
    * Data Base functions declarations
    * Author Xema Maestre && HEctor Ochando
    * <maestrequi@esat-alumni.com>
*/


#ifndef __DATA_BASE_CONTROLLER_H__ 
#define __DATA_BASE_CONTROLLER_H__ 1 

#include "esat_extra/sqlite3.h"



class DataBaseController{
    public:
    // Public functions
        
        static DataBaseController& Instance();
        
        //** Importante **
        // Constructor de copia
        DataBaseController(const DataBaseController&) = delete; // Palabra clave, para decirle que no exista ese constructor. Tambien se puede poner default en vez de delete para que lo haga el compilador por defecto
        void operator = (const DataBaseController&) = delete; // Sobre carga de operador para la clase
        ~DataBaseController(); // Destructor

        void ShowWindow();
        bool OpenDB(char *name);

        void SetNumTables(int);
        void SetTableName(int, char*);

        void GetTablesName();

    private:
    // Private functions
    sqlite3* db;
    char **tables_name;
    int num_tables;
    char *err_msg;


    
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