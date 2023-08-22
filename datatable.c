// Copyright (C) 2023 Kamiar Bahri
//
#include <stdio.h>
#include <stdlib.h>
#include "datatable.h"

// new_datatable creates new datatable with
// no columns and rows.
DATATABLE* new_datatable(char* tbl_name){

    DATATABLE* dt;
    dt = (DATATABLE*)malloc(sizeof(DATATABLE*));
    dt->col_count = 0;
    dt->row_count = 0;

    dt->name=(char*)malloc(sizeof(char*));
    dt->name = tbl_name;

    return dt;
}

// datatable_new_row creates a new row to the datatable,
// This row is not attached to the datatable.
ROW* datatable_new_row(DATATABLE* dt){

    ROW* row = (ROW*)malloc(sizeof(ROW*));

    int i;
    for(i=0; i < dt->col_count; i++){        
        row->cols[i] = (COLUMN*)malloc(sizeof(COLUMN*));
        row->cols[i]->name=(char*)malloc(sizeof(char*));
        row->cols[i]->name = dt->cols[i]->name;
    }
    
    return row;
}

// datatable_addrow adds a new row to the datatable
void datatable_addrow(DATATABLE* dt, ROW* row){
    dt->row_count++;
    dt->rows[dt->row_count-1] = (ROW*)malloc(sizeof(ROW*));
    dt->rows[dt->row_count-1] = row;
}

// datatable_add_col adds a new column to the datatable.
void datatable_add_col(DATATABLE* dt, char* colname){
    dt->col_count++;

    dt->cols[dt->col_count-1] = (TABLECOLUMN*)malloc(sizeof(TABLECOLUMN*));
    dt->cols[dt->col_count-1]->name=(char*)malloc(sizeof(char*));
    dt->cols[dt->col_count-1]->name = colname;
}

// DATATABLE* new_datatable(char* tbl_name, int numCols,int numRows){
//     int i;
//     DATATABLE* dt;
//     dt = malloc(sizeof*dt);

//     dt->name=(char*)malloc(sizeof(char*));
//     dt->name = tbl_name;

//     for(i=0; i < numRows; i++){
//          dt->rows[i] = (ROW*)malloc(sizeof(ROW*));
//         int j;
//         for(j=0; j < numCols; j++){
//             dt->rows[i]->cols[j] = (COLUMN*)malloc(sizeof(COLUMN*));
//         }        
//     }
//     return dt;
// }
