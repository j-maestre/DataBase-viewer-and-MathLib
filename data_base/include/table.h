/**
 * @file table.h
 * @author Hector Ochando <ochandoca@esat.alumni.com>
 * @brief 
 * 
 */

#ifndef __TABLE_H__
#define __TABLE_H__ 1

typedef struct Table Table;

enum DataType{
  UNDEFINED = -1,          //9??
  BIT = 1,                 //3
  INT = 2,                 //3
  DEC = 3,                 //3
  BLOB = 4,                //4
  BOOL = 5,                //4
  FLOAT = 6,               //5
  BIGINT = 7,              //6
  BINARY = 8,              //6
  DOUBLE = 9,              //6
  DECIMAL = 10,            //7
  TINYINT = 11,            //7
  BOOLEAN = 12,            //7
  INTEGER = 13,            //7
  TINYBLOB = 14,           //8
  SMALLINT = 15,           //8
  LONGBLOB = 16,           //8
  MEDIUMINT = 17,          //9
  MEDIUMBLOB = 18,         //10
  DOUBLE_PRECISION = 19,   //16
  DATE = 20,               //4---
  CHAR = 21,               //4--
  TEXT = 22,               //4--
  TIME = 23,               //4--
  YEAR = 24,               //4--
  VARCHAR = 25,            //7--
  NVARCHAR = 26,           //8--
  DATETIME = 27,           //8--
  TINYTEXT = 28,           //8--
  LONGTEXT = 29,           //8--
  VARBINARY = 30,          //9--
  TIMESTAMP = 31,          //9--
  MEDIUMTEXT = 32,         //10--
};

/**
 * @brief Create a Teable object
 * 
 * @param table Reference of the pointer to the Table object.
 * @param col_num Number of columns.
 * @param row_num Number of rows.
 * @return int Error: 0 == OK
 */
int  CreateTable(Table **table, int col_num, int reg_max_size);

/**
 * @brief Insert col_names in the Table
 * 
 * @param table Pointer to the Table where is gonna be inserted the column names
 * @param col_names Pointer to the column names.
 */
void InsertColNames(Table *table, char **col_names);

void InsertColTypes(Table *table, int *col_types);

/**
 * @brief Insert a data row into the Table in the current position.
 * 
 * The current position can be modified with NextRow();
 *  
 * @param table Table is where is gonna be inserted row_data
 * @param index Index of the row on row_data is gonna be inseted
 * @param row_data Row data is gonna be inseted in the Table
 * @return int Errot: 0 == OK
 */
int InsertRow(Table *table, char**row_data);

/**
 * @brief This function run the Table and execute the callback.
 * 
 * The callback will recibe from the arguments the user_data into void *,
 * the column number into int, the row of values into the first char **,
 * and the col name int the second char **.
 * 
 * @param table The Table we whant to run.
 * @param callback The function is gonna be executed with the data.
 * @param user_data The user data you can pass to the callback
 * @return int Error: 0 == OK
 */
int  RunTable(Table *table, int (*callback)(Table *, void *, int, char **, char **), void *user_data);

/**
 * @brief This function run the Table and execute the callback.
 * 
 * The callback will recibe from the arguments the user_data into void *,
 * the column number into int, the row of values into the first char **,
 * and the col name int the second char **.
 * 
 * @param table The Table we whant to run.
 * @param callback The function is gonna be executed with the data.
 * @param user_data The user data you can pass to the callback
 * @param from The index of the row where the callback starts 
 * @param to The index of the row where the callback finish
 * @return int Error: 0 == OK
 */
int  RunTable(Table *table, int (*callback)(Table *, void *, int, char **, char **), void *user_data, int from, int to);


/**
 * @brief Get the columns names of the Table
 * 
 * @param table The Table we gonna be get the columns names
 * @return char** Pointer to the name of the columns
 */
char** GetColumnsNames(Table *table);

int* GetColumnsType(Table *table);

/**
 * @brief Get the columns number of the Table
 * 
 * @param table Pointer to the Table we gonna have the columns number
 * @return int Number of the columns
 */
int GetColumnsNumber(Table *table);

/**
 * @brief Get the rows rumber of the Table
 * 
 * @return int Number of the rows
 */
int GetRowsNumber(Table *table);

/**
 * @brief This function free memory from the table and set the table to nullptr.
 * 
 * @param table Pointer to the Tabel is gonna be deleted.
 */
void DestroyTable(Table *table);

void SetTableName(Table *table, char *name);

char* GetTableName(Table *table);

#endif