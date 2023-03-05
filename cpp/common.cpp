#ifndef COMMON_CPP_INCLUDED
#define COMMON_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/main.hpp"

#include "../lib/logs.hpp"

#include "insertion.cpp"
#include "selection.cpp"
#include "bubble.cpp"
#include "quick.cpp"
#include "merge.cpp"
#include "lsd.cpp"
#include "msd.cpp"
#include "tests.cpp"


Array* array_ctor (size_t size) {

    Array* array = (Array*) calloc (ARRAY_SIZE, 1);
    assert (array);


    array->elements = (int*) calloc (size * INT_SIZE, 1);
    assert (array->elements);

    array->size = size;


    array_to_zero (array);


    return array;
}


Array* array_generate (size_t size) {

    Array* array = array_ctor (size);


    array_randomize (array);


    return array;
}


Array* array_dup (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return nullptr; }


    Array* new_array = array_ctor (array->size);

    for (size_t i = 0; i < array->size; i++) {

        new_array->elements [i] = array->elements [i];
    }


    return new_array;
}


Return_code array_copy (Array* src, Array* dst) {

    if (!src) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }
    if (!dst) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    if (dst->size != src->size || dst->elements == nullptr) {

        free (dst->elements);
        dst->elements = (int*) calloc (src->size * INT_SIZE, 1);
        dst->size = src->size;
    }


    for (size_t i = 0; i < src->size; i++) {

        dst->elements [i] = src->elements [i];
    }


    return SUCCESS;
}


Return_code array_randomize (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    srand ((unsigned int) time (nullptr));

    for (size_t i = 0; i < array->size; i++) {

        if (rand () % 2) {

            array->elements [i] = rand ();
            continue;
        }

        array->elements [i] = -1 * rand ();
    }


    return SUCCESS;
}


Return_code array_to_zero (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    for (size_t i = 0; i < array->size; i++) {

        array->elements [i] = 0;
    }


    return SUCCESS;
}


Return_code array_reverse (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    Array* temp = array_ctor (array->size);

    for (size_t i = 0; i < array->size; i++) {

        temp->elements [i] = array->elements [array->size - 1 - i];
    }


    array_copy (temp, array);
    array_dtor (temp);


    return SUCCESS;
}


Return_code array_print (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    printf ("\n");
    for (size_t i = 0; i < array->size; i++) {

        printf ("[%-2zd] = %d\n", i, array->elements [i]);
    }
    printf ("\n");


    return SUCCESS;
}


Return_code array_dtor (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    free (array->elements);
    free (array);


    return SUCCESS;
}


Return_code swap_int (int* int1, int* int2) {

    if (!int1) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }
    if (!int2) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    *int1 = *int1 xor *int2; // int1 = XOR
    *int2 = *int1 xor *int2; // int2 = int1
    *int1 = *int1 xor *int2; // int1 = int2


    return SUCCESS;
}


//--------------------------------------------------
#endif