/*
    * Data Base functions declarations
    * Author Xema Maestre && HEctor Ochando
    * <maestrequi@esat-alumni.com>
*/


#ifndef __DATA_BASE_CONTROLLER_H__ 
#define __DATA_BASE_CONTROLLER_H__ 1 

class DataBaseController{
    public:
    // Public functions
        
        // Constructor
        DataBaseController();
        
        //** Importante **
        // Constructor de copia
        DataBaseController(const DataBaseController&) = delete; // Palabra clave, para decirle que no exista ese constructor. Tambien se puede poner default en vez de delete para que lo haga el compilador por defecto
        void operator = (const DataBaseController&) = delete; // Sobre carga de operador para la clase
        ~DataBaseController(); // Destructor
        void ShowTable();

    private:
    // Private functions

    // Consulta Select
    void ExecuteSelect(char *query); // Devolverá una tabla

    // Cualquier tipo de consulta excepto Select
    void ExecuteQuery(char *query);


};


DataBaseController::DataBaseController(){

};

#endif