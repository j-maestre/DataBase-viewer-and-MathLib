/**
 * @file table.h
 * @author Xema Maestre <maestrequi@esat-alumni.com>
 * @author Hector Ochando <ochandoca@esat.alumni.com>
 * @brief 
 * 
 */

#ifndef __TABLE_H__
#define __TABLE_H__ 1

typedef struct Table Table;

/**
 * @brief Create a Teable object
 * 
 * @param table Reference of the pointer to the Table object.
 * @param col_num Number of columns.
 * @param row_num Number of rows.
 * @return int 
 */
int  CreateTeable(Table **table, int col_num, int row_num);

/**
 * @brief Insert col_names in the Table
 * 
 * @param table 
 * @param col_names 
 */
void InsertColNames(Table *table, char **col_names);

/**
 * @brief Insert a data row into the Table in the current position.
 * 
 * The current position can be modified with NextRow();
 * 
 * @param table 
 * @param row_data 
 */
void InsertRow(Table *table, char**row_data);

/**
 * @brief Change to the next row of the Table to be inserted in InsertRow();
 * 
 * @param table 
 */
void NextRow(Table *table);

/**
 * @brief This function run the Table and execute the callback.
 * 
 * The callback will recibe from the arguments the user_data into void *,
 * the column number into int, the row of values into the first char **,
 * and the col name int the second char **.
 * 
 * @param table The Table we whant to run.
 * @param callback The function is gona be executed with the data.
 * @param user_data The user data you can pass to the callback
 * @return int 
 */
int  RunTable(Table *table, int (*callback)(void *, int, char **, char **), void *user_data);

/**
 * @brief This function free memory from the table and set the table to nullptr.
 * 
 * @param table This is the Tabel you want to delete.
 */
void DestroyTable(Table *table);

/**
 * @brief This function casts the void pointer into Table pointer.
 * 
 * @param talbe Void pointer to the table you want to cast.
 * @return Table* 
 */
Table* TableCast(void *talbe);

#endif