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

void print(vector<DataStruct> v);

DataStruct fill(string *table, int size);

vector<DataStruct> sort(vector<DataStruct> v);

#endif // LAB_5_H
