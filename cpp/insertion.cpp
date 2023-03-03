#ifndef INSERTION_CPP_INCLUDED
#define INSERTION_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/insertion.hpp"


Return_code insertion_sort (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    for (size_t i = 1; i < array->size; i++) {

        size_t current_position = i;

        while (array->elements [current_position] > array->elements [current_position - 1]) {

            swap_int (&array->elements [current_position], &array->elements [current_position - 1]);
            current_position -= 1;
        }
    }


    return SUCCESS;
}


//--------------------------------------------------
#endif