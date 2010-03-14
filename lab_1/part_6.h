/**
  @defgroup lab_1_part_6 Part 6
  @ingroup lab_1
  @{
*/
#ifndef PART_6_H
#define PART_6_H
#include <iostream>
#include <vector>
#include <cstdlib>

#define get_size_array(array) sizeof(array) / sizeof(array[0])

using namespace std;

template <typename T> void print_array(T array[], int size);

template <typename T> void print_vector(vector<T> v);

template <typename T> T rand_range(T a, T b);

void full_random(double *array, int size);

template <class T> vector<T> sort_vector(vector<T> v);

void part_6(void);




#endif // PART_6_H
/// @}
