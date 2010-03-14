#ifndef LAB_5_H
#define LAB_5_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
/** @addtogroup lab_5
  @{ */
typedef struct
{
    int key1;
    int key2;
    string str;
} DataStruct;

typedef vector<DataStruct> container_type;

class DataStructManager
{
private:
    container_type __container;
public:
    DataStructManager(string *table, int size);
    void sort(void);
    void print(void);
};

/// @}
#endif // LAB_5_H
