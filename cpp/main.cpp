

#include "../hpp/main.hpp"


int main (void) {


    Sort_info info = { .reversed = false, .print = false, .partition = MIDDLE }; // partition ни на что не влияет, он задается позже

    sorts_test (3321000, 10000000, 100000, &info);


    printf ("\ngoodbye!\n");


    return 0;
}

