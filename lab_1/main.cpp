#include <cstdlib>
#include <iostream>
#include "part_1.h"
#include "part_2.h"
#include "part_3.h"
#include "part_4.h"
#include "part_5.h"
#include "part_6.h"
#include "../lab_helper.h"

int unsorted_array[] = {3, 23, 6, 7, 9, 0, 48, 3, 4, 5, 7, 8};

void notice_part(int part)
{
    std::cout << endl << "============== Part: " << part << " ==============="<< endl;
}

int main(void)
{
    notice_part(1);
    part_1(unsorted_array, get_size(unsorted_array));
    notice_part(2);
    part_2(unsorted_array, get_size(unsorted_array));
    notice_part(3);
    part_3(unsorted_array, get_size(unsorted_array));
    notice_part(4);
    part_4("part_4_input.txt");
    notice_part(5);
    part_5();
    notice_part(6);
    part_6();
    win32cmd();
    return EXIT_SUCCESS;
}
