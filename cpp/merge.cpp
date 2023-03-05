#ifndef MERGE_CPP_INCLUDED
#define MERGE_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/sorts.hpp"


Return_code merge_sort (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    if (array->size <= 1) { return SUCCESS; }



    size_t middle = array->size / 2; //index


    Array Array1 = { .elements = array->elements,          .size = middle };
    Array Array2 = { .elements = array->elements + middle, .size = array->size - middle };

    Sort_info new_info = { .reversed = info->reversed, .print = false, .partition = info->partition };


    merge_sort (&Array1, &new_info);
    merge_sort (&Array2, &new_info);


    merge (array, middle);


    if (info->print) { array_print (array); }


    return SUCCESS;
}


Return_code merge (Array* array, size_t middle) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    Array* temp = array_ctor (array->size);


    size_t i1          = 0;
    size_t i2          = middle;
    size_t write_index = 0;

    while (i1 < middle && i2 < array->size) { //основная часть

        if (array->elements [i1] <= array->elements [i2]) {

            temp->elements [write_index] = array->elements [i1];
            write_index += 1;
            i1 += 1;
            continue;
        }

        temp->elements [write_index] = array->elements [i2];
        write_index += 1;
        i2 += 1;
        continue;
    }



    while (i1 < middle) { //выполнится только одно из двух прицеплений

        temp->elements [write_index] = array->elements [i1];
        write_index += 1;
        i1 += 1;
    }

    while (i2 < array->size) { //выполнится только одно из двух прицеплений

        temp->elements [write_index] = array->elements [i2];
        write_index += 1;
        i2 += 1;
    }


    array_copy (temp, array);


    array_dtor (temp);


    return SUCCESS;
}


//--------------------------------------------------
#endif