/*
    * Data Base functions declarations
    * Author Xema Maestre && HEctor Ochando
    * <maestrequi@esat-alumni.com>
*/

#ifndef __TABLE_H__ 
#define __TABLE_H__ 1 

// Las structs son por defecto publicas

typedef struct Table Table;

    // Obligamos a pasar por esta funcion para hacer el malloc
    void CreateTable(Table** t);
    void DestroyTable(Table* t);

    int  CreateTeable(Table** table, int col_num, int row_num);
    void InsertColNames(Table *table, char** col_names);
    void InsertRow(Table *table, char **row_data);
    void NextRow(Table *table);
    int  RunTable(Table *table, int (*callback)(void* , int, char** , char** ), void* user_data);
    void DestroyTable(Table *table);


#endif