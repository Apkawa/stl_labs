#include <iostream>
#include <vector>
#ifdef _WIN32_C_LIB
    #include <cstdio>
#endif //WIN32
#include <cstdlib>

#define get_size_array(array) sizeof(array) / sizeof(array[0])
using namespace std;
void part_1();

int unsorted_array[] = {3, 23, 6, 7, 9, 0, 48, 3, 4, 5, 7, 8};

int main(int argc, char *argv[])
{
    part_1();
#ifdef _WIN32_C_LIB
    getchar();
#endif //WIN32
    return EXIT_SUCCESS;
}

void part_1(void){
    vector<int> v;
    int i;

    cout << "write from array\n";
    for (i = 0; i < get_size_array(unsorted_array); ++i){
        v.push_back(unsorted_array[i]);
        cout << v[i] << ",";
    }
    cout << "\nsorted\n";
    // bubble sort method Q(n^2)
    bool t = true;
    int temp;
    while (t){
        t = false;
        for (i=0; i < v.size() - 1; ++i){
            if (v[i] > v[i+1]){
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                t = true;
            }
        }
    }
    for (i=0; i < v.size(); ++i) {
        cout << v[i] << ",";
    }
}
