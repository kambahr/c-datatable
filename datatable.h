// Copyright (C) 2023 Kamiar Bahri
//
#ifndef DATATBLE_H
#define DATATBLE_H

#define MAX_COLUMNS 526
#define MAX_ROWS    10000

typedef struct row_column{
    char* name;
    char* value;
}COLUMN;

typedef struct table_column{
    char* name;
}TABLECOLUMN;

typedef struct row{
    COLUMN* cols[MAX_COLUMNS];
}ROW;

typedef struct datatable{
    ROW* rows[MAX_ROWS];
    TABLECOLUMN* cols[MAX_COLUMNS];
    const char* name;
    int row_count;
    int col_count;
}DATATABLE;

// new_datatable creates new datatable with
// no columns and rows.
DATATABLE* new_datatable(char* tbl_name);

// datatable_new_row creates a new row to the datatable,
// This row is not attached to the datatable.
ROW* datatable_new_row(DATATABLE* dt);

// datatable_addrow adds a new row to the datatable
void datatable_addrow(DATATABLE* dt, ROW* row);

// datatable_add_col adds a new column to the datatable.
void datatable_add_col(DATATABLE* dt, char* colname);

// DATATABLE* new_datatable(char* tbl_name, int numCols,int numRows);

#endif