#ifndef QUICK_CPP_INCLUDED
#define QUICK_CPP_INCLUDED
//--------------------------------------------------


#include "../hpp/sorts.hpp"


Return_code quick_sort (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return BAD_ARGS; }


    if (array->size <= 1) { return SUCCESS; }



    int pivot = pick_pivot (array, info); // value

    size_t middle_pos = partition (array, pivot);


    Array array1 = { .elements = array->elements,              .size = middle_pos };
    Array array2 = { .elements = array->elements + middle_pos, .size = array->size - middle_pos };

    Sort_info new_info = { .reversed = info->reversed, .print = false, .partition = info->partition };


    quick_sort (&array1, &new_info);
    quick_sort (&array2, &new_info);


    if (info->print) { array_print (array); }


    return SUCCESS;
}


size_t partition (Array* array, int pivot) {

    if (!array) { LOG_ERROR (BAD_ARGS); return 0; }


    size_t left  = 0;
    size_t right = array->size - 1;

    while (true) {

       while (array->elements [left] < pivot && left < right) {

            left += 1;
       }

       while (array->elements [right] > pivot && left < right) {

            right -= 1;
       }

       if (left >  right) { return left; }
       if (left == right) { return (array->elements [left] >= pivot) ? (left):(left + 1); }; // в общем случае, этот элемент мы ни с чем не сравнивали,
                                                                                             // непонятно к какой половине он относится!


       swap_int (&array->elements [left], &array->elements [right]);

       left  += 1;
       right -= 1;
    }


    LOG_ERROR (CRITICAL);
    return 0;
}


int pick_pivot (Array* array, Sort_info* info) {

    if (!array) { LOG_ERROR (BAD_ARGS); return 0; }


    switch (info->partition) {

        case MIDDLE:      return pick_middle (array);
        case RANDOM:      return pick_random (array);
        case MEDIAN_OF_3: return pick_median_of_3 (array);

        default: LOG_ERROR (CRITICAL); return 0;
    }


    LOG_ERROR (CRITICAL);
    return 0;
}


int pick_middle (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return 0; }


    return array->elements [array->size / 2];
}


int pick_random (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return 0; }


    return array->elements [rand () % array->size];
}


int pick_median_of_3 (Array* array) {

    if (!array) { LOG_ERROR (BAD_ARGS); return 0; }


    size_t i1 = 0;
    size_t i2 = array->size / 2;
    size_t i3 = array->size - 1;

    int v1 = array->elements [i1];
    int v2 = array->elements [i2];
    int v3 = array->elements [i3];


    int ans = 0;

    if      ((v1 <= v2 && v2 <= v3) || (v3 <= v2 && v2 <= v1)) { ans = v2; }
    else if ((v2 <= v1 && v1 <= v3) || (v3 <= v1 && v1 <= v2)) { ans = v1; }
    else                                                       { ans = v3; }


    return ans;
}


//--------------------------------------------------
#endif