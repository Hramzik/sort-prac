#ifndef BUBBLE_CPP_INCLUDED
#define BUBBLE_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/sorts.hpp"


Return_code bubble_sort (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    for (size_t already_sorted = 0; already_sorted < array->size; already_sorted++) {

        size_t bubble = 0;
        bool swapped = false;

        while ((bubble) < (array->size - 1 - already_sorted)) {

            if (array->elements [bubble] > array->elements [bubble + 1]) {

                swap_int (&array->elements [bubble], &array->elements [bubble + 1]);
                swapped = true;
            }

            bubble += 1;
        }


        if (!swapped) { break; }
    }


    if (info->print) { array_print (array); }


    return SUCCESS;
}


//--------------------------------------------------
#endif