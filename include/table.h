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

int CreateTeable(Table **table, int col_num, int row_num);
void InsertColNames(Table *table, char **col_names);
void InsertRow(Table *table, char**row_data);
void NextRow(Table *table);
int RunTable(Table *table, int (*callback)(void *, int, char **, char **), void *user_data);
void DestroyTable(Table *table);

#endif