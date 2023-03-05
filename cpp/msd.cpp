#ifndef MSD_CPP_INCLUDED
#define MSD_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/sorts.hpp"


Return_code msd_sort (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    if (array->size <= 1) { return SUCCESS; }


    size_t split = msd_split (array);


    Array array1 = { .elements = array->elements,         .size = split };
    Array array2 = { .elements = array->elements + split, .size = array->size - split };

    Sort_info info1 = { .reversed = true,  .print = info->print, .partition = info->partition };
    Sort_info info2 = { .reversed = false, .print = info->print, .partition = info->partition };


    msd_sort_by_all_digits (&array1, &info1);
    msd_sort_by_all_digits (&array2, &info2);


    if (info->reversed) { array_reverse (array); }


    if (info->print) { array_print (array); }


    return SUCCESS;
}


size_t msd_split (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    Array* temp_array = array_ctor (array->size); //буфер


    size_t positive = array->size - 1;
    size_t negative = 0;

    for (size_t i = 0; i < array->size; i++) {

        int current = array->elements [i];

        if (current >= 0) {

            temp_array->elements [positive] = current;
            positive -= 1;
            continue;
        }

        temp_array->elements [negative] = current;
        negative += 1;
    }


    array_copy (temp_array, array);
    array_dtor (temp_array);


    return negative; //первый положительный
}


Return_code msd_sort_by_all_digits (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }
    if (!info)  { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    size_t max_digit_num = get_max_digit_num (array);
    msd_sort_from_nth_digit (array, max_digit_num);


    if (info->reversed) { array_reverse (array); }


    return SUCCESS;
}


Return_code msd_sort_from_nth_digit (Array* array, size_t n) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    if (n == 0) { return SUCCESS; } // база индукции


    size_t amount_of_digits [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //a[i] = у скольки чисел есть цифра i

    for (size_t i = 0; i < array->size; i++) {

        size_t current_digit = digit (array->elements [i], n);
        amount_of_digits [current_digit] += 1;
    }


    size_t total = 0;

    for (size_t i = 0; i < 10; i++) { //заменяем на префиксные суммы; a[i] = у скольки чисел цифры меньше i 

        size_t temp = amount_of_digits [i];
        amount_of_digits [i] = total;
        total += temp;
    }


    msd_fill_numbers (array, n, amount_of_digits);


    return SUCCESS;
}


Return_code msd_fill_numbers (Array* array, size_t n, size_t* prefix_sums) {

    if (!array)       { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }
    if (!prefix_sums) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    Array* temp_array = array_ctor (array->size); //буфер

    for (size_t i = 0; i < array->size; i++) {

        size_t current_digit = digit (array->elements [i], n);
        temp_array->elements [prefix_sums [current_digit]] = array->elements [i];

        prefix_sums [current_digit] += 1; //запись будет слева направо p[i] = у скольки чисел цифры <= i 
    }


    array_copy (temp_array, array);
    array_dtor (temp_array);


    Array array_0 = { .elements = array->elements, .size = prefix_sums [0] }; // вырожденный случай
    msd_sort_from_nth_digit (&array_0, n - 1);

    for (size_t i = 1; i < 10; i++) {

        Array array_i = { .elements = array->elements + prefix_sums [i - 1], .size = prefix_sums [i] - prefix_sums [i - 1]};
        msd_sort_from_nth_digit (&array_i, n - 1);
    }


    return SUCCESS;
}


// функции определения свойств цифр в числе реализованы в lsd.cpp


//--------------------------------------------------
#endif