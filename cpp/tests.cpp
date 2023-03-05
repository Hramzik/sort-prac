#ifndef TESTS_CPP_INCLUDED
#define TESTS_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/common.hpp"


size_t sort_time ( Return_code (sort_func) (Array*, Sort_info*), Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    Array* my_array = array_dup (array);


    //-----------------------
    clock_t start = clock (); //sleep (1);

    sort_func (my_array, info); // array_print (my_array);

    clock_t end = clock ();
    //-----------------------


    array_dtor (my_array);


    return (end - start) * 1000 / CLOCKS_PER_SEC; // ms
}


size_t sort_avg_time ( Return_code (sort_func) (Array*, Sort_info*), Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    Sort_info do_print   = { .reversed = info->reversed, .print = info->print, .partition = info->partition };
    Sort_info dont_print = { .reversed = info->reversed, .print = false,       .partition = info->partition };


    size_t time1 = sort_time (sort_func, array, &dont_print) / 5;
    size_t time2 = sort_time (sort_func, array, &dont_print) / 5;
    size_t time3 = sort_time (sort_func, array, &dont_print) / 5;
    size_t time4 = sort_time (sort_func, array, &dont_print) / 5;
    size_t time5 = sort_time (sort_func, array, &do_print)   / 5;

    return time1 + time2 + time3 + time4 + time5;
}


Return_code sorts_test (size_t start_size, size_t max_size, size_t step_size, Sort_info* info) {

    for (size_t n = start_size; n < max_size; n += step_size) {

        sorts_one_test (n, info);
    }


    return SUCCESS;
}


Return_code sorts_one_test (size_t size, Sort_info* info) {

    Array* array = array_generate (size);


    Sort_info info_middle      = *info; info_middle.partition      = MIDDLE;
    Sort_info info_random      = *info; info_random.partition      = RANDOM;
    Sort_info info_median_of_3 = *info; info_median_of_3.partition = MEDIAN_OF_3;


    /*write ("insertion", size, sort_avg_time (insertion_sort, array,  info));
    write ("bubble",    size, sort_avg_time (bubble_sort,    array,  info));
    write ("selection", size, sort_avg_time (selection_sort, array,  info));*/
    write ("quick_mdl", size, sort_avg_time (quick_sort,     array, &info_middle));
    write ("quick_rnd", size, sort_avg_time (quick_sort,     array, &info_random));
    write ("quick_mo3", size, sort_avg_time (quick_sort,     array, &info_median_of_3));
    write ("merge",     size, sort_avg_time (merge_sort,     array,  info));
    write ("lsd",       size, sort_avg_time (lsd_sort,       array,  info));
    write ("msd",       size, sort_avg_time (msd_sort,       array,  info));


    array_dtor (array);


    return SUCCESS;
}


Return_code write (const char* name, size_t size, size_t result) {

    if (!name) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    char file_name [strlen (name) + 5 + 5] = "";
    strcat (file_name, "work/");
    strcat (file_name, name);
    strcat (file_name, ".txt");
    FILE* file = fopen (file_name, "a");


    fprintf (file, "%-8zd, %-8zd\n", size, result);


    fclose (file);


    return SUCCESS;
}


//--------------------------------------------------
#endif