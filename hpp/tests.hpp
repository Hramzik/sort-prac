#ifndef TESTS_HPP_INCLUDED
#define TESTS_HPP_INCLUDED
//--------------------------------------------------


#include "common.hpp"


size_t      sort_time      ( Return_code (sort_func) (Array*), Array* array);
size_t      sort_avg_time  ( Return_code (sort_func) (Array*), Array* array);
Return_code sorts_test     (size_t start_size, size_t max_size, size_t step_size);
Return_code sorts_one_test (size_t size);


//--------------------------------------------------
#endif