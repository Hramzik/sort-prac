#ifndef INSERTION_CPP_INCLUDED
#define INSERTION_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/sorts.hpp"


Return_code insertion_sort (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    for (size_t i = 1; i < array->size; i++) {

        size_t current_position = i;

        while ((current_position > 0) && array->elements [current_position] < array->elements [current_position - 1]) {

            swap_int (&array->elements [current_position], &array->elements [current_position - 1]);
            current_position -= 1;
        }
    }


    if (info->print) { array_print (array); }


    return SUCCESS;
}


//--------------------------------------------------
#endif