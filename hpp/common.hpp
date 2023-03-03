#ifndef COMMON_HPP_INCLUDED
#define COMMON_HPP_INCLUDED
//--------------------------------------------------


#include <sys\stat.h>
#include <locale.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


#include "../lib/types/Return_code.hpp"


typedef struct Array {

    int* elements;
    size_t size;

} Array; const size_t ARRAY_SIZE = sizeof (Array);


const size_t INT_SIZE = sizeof (int);


Array*      array_ctor      (size_t size);
Array*      array_generate  (size_t size);
Array*      array_dup       (Array* array);
Return_code array_randomize (Array* array);
Return_code array_dtor      (Array* array);

Return_code swap_int (int* int1, int* int2);


//--------------------------------------------------
#endif