# c-datatable
## A C Implementation of Data Table (Rows and Columns)

#### Example
```c
    DATATABLE* dt = new_datatable("Guitar is the song");

    datatable_add_col(dt, "Country");
    datatable_add_col(dt, "State");
    datatable_add_col(dt, "City");

    ROW* row = datatable_new_row(dt);
    row->cols[0]->value = "U.S.A";
    row->cols[1]->value = "California";
    row->cols[2]->value = "Los Angeles";
    datatable_addrow(dt, row);

    row = datatable_new_row(dt);
    row->cols[0]->value = "France";
    row->cols[1]->value = "Alsace";
    row->cols[2]->value = "Strasbourg";
    datatable_addrow(dt, row);

    row = datatable_new_row(dt);
    row->cols[0]->value = "Spain";
    row->cols[1]->value = "Albacete";
    row->cols[2]->value = "Nerpio";
    datatable_addrow(dt, row);

    printf("\n*** TABLE: %s ***\n", dt->name);

    int i,j;
    for(j=0; j < dt->col_count; j++){
        printf("    %s ",dt->cols[j]->name);
    }
    printf("\n");

    for(i=0; i < dt->row_count;i++){
        printf("[%d] ",i+1); 
        for(j=0; j < dt->col_count; j++){
            printf("%s\t",dt->rows[i]->cols[j]->value);
        }
        printf("\n");
    }
    printf("\n");

Output:

*** TABLE: Guitar is the song ***
    Country     State           City 
[1] U.S.A       California      Los Angeles
[2] France      Alsace          Strasbourg
[3] Spain       Albacete        Nerpio
```
