#ifndef SELECTION_CPP_INCLUDED
#define SELECTION_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/sorts.hpp"


Return_code selection_sort (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    for (size_t current_place = 0; current_place + 1 < array->size; current_place++) {

        size_t current_min = current_place; // index

        for (size_t i = current_place + 1; i < array->size; i++) {

            if (array->elements [i] < array->elements [current_min]) {

                current_min = i;
            }
        }

        if (current_min != current_place) { // иначе xor дает 0

            swap_int (&array->elements [current_place], &array->elements [current_min]);
        }
    }


    if (info->print) { array_print (array); }


    return SUCCESS;
}


//--------------------------------------------------
#endif