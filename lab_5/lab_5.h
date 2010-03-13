#ifndef LAB_5_H
#define LAB_5_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct
{
    int key1;
    int key2;
    string str;
} DataStruct;

typedef vector<DataStruct> container_type;

void print(container_type v);

DataStruct fill(string *table, int size);

container_type sort(container_type v);

#endif // LAB_5_H
