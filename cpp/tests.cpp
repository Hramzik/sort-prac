#ifndef TESTS_CPP_INCLUDED
#define TESTS_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/common.hpp"


size_t sort_time ( Return_code (sort_func) (Array*), Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    Array* my_array = array_dup (array);


    //-----------------------
    clock_t start = clock (); //sleep (1);

    sort_func (my_array);

    clock_t end = clock ();
    //-----------------------


    array_dtor (my_array);


    return (end - start) * 1000 / CLOCKS_PER_SEC; // ms
}


size_t sort_avg_time ( Return_code (sort_func) (Array*), Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    size_t time1 = sort_time (sort_func, array) / 5;
    size_t time2 = sort_time (sort_func, array) / 5;
    size_t time3 = sort_time (sort_func, array) / 5;
    size_t time4 = sort_time (sort_func, array) / 5;
    size_t time5 = sort_time (sort_func, array) / 5;

    return time1 + time2 + time3 + time4 + time5;
}


Return_code sorts_test (size_t start_size, size_t max_size, size_t step_size) {

    for (size_t n = start_size; n < max_size; n += step_size) {

        sorts_one_test (n);
    }


    return SUCCESS;
}


Return_code sorts_one_test (size_t size) {

    Array* array = array_generate (size);

    size_t time_insertion = sort_avg_time (insertion_sort, array);
    printf ("insertion_sort (%zd) - %zdms\n", size, time_insertion);

    return SUCCESS;
}


//--------------------------------------------------
#endif