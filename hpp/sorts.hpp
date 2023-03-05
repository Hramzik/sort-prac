#ifndef SORTS_HPP_INCLUDED
#define SORTS_HPP_INCLUDED
//--------------------------------------------------


#include "common.hpp"


Return_code insertion_sort (Array* array, Sort_info* info);
Return_code bubble_sort    (Array* array, Sort_info* info);
Return_code selection_sort (Array* array, Sort_info* info);


Return_code quick_sort       (Array* array, Sort_info* info);
size_t      partition        (Array* array, int pivot);
int         pick_pivot       (Array* array, Sort_info* info);
int         pick_middle      (Array* array);
int         pick_random      (Array* array);
int         pick_median_of_3 (Array* array);

Return_code merge_sort (Array* array, Sort_info* info);
Return_code merge      (Array* array, size_t middle);


Return_code lsd_sort               (Array* array, Sort_info* info);
size_t      lsd_split              (Array* array);
Return_code lsd_sort_by_all_digits (Array* array, Sort_info* info);
Return_code lsd_sort_by_nth_digit  (Array* array, size_t n, Sort_info* info);
Return_code lsd_fill_numbers       (Array* array, size_t n, size_t* prefix_sums);
size_t      get_max_digit_num      (Array* array);
size_t      digit                  (int n, size_t k);
size_t      get_digit_num          (int n);


Return_code msd_sort                (Array* array, Sort_info* info);
size_t      msd_split               (Array* array);
Return_code msd_sort_by_all_digits  (Array* array, Sort_info* info);
Return_code msd_sort_from_nth_digit (Array* array, size_t n);
Return_code msd_fill_numbers        (Array* array, size_t n, size_t* prefix_sums);


//--------------------------------------------------
#endif