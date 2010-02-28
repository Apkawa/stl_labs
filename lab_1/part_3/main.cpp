#include <iostream>
#include <vector>
#ifdef _WIN32_C_LIB
    #include <cstdio>
#endif //WIN32
#include <cstdlib>

#define get_size_array(array) sizeof(array) / sizeof(array[0])
using namespace std;
void part_3();

int unsorted_array[] = {3, 23, 6, 7, 9, 0, 48, 3, 4, 5, 7, 8};

int main(int argc, char *argv[])
{
    part_3();
#ifdef _WIN32_C_LIB
    getchar();
#endif //WIN32
    return EXIT_SUCCESS;
}

void part_3(void){
    vector<int> v;
    int i;

    cout << "write from array\n";
    for (i = 0; i < get_size_array(unsorted_array); ++i){
        v.push_back(unsorted_array[i]);
        cout << v[i] << ",";
    }
    cout << "\nsorted\n";

    // paste sort method Q(n^2)
    vector<int>::iterator iter;
    int key;
    int j;
    for (i = 0, iter=v.begin(); iter < v.end(); i++, iter++){
        key = *iter;
        j = i - 1;
        while(j >= 0 & *(v.begin()+j) > key) {
            *(v.begin()+(j+1)) = *(v.begin()+j);
            j--;
        }
        *(v.begin()+(j+1)) = key;

    }
    //end sort

    for (i=0; i < v.size(); ++i) {
        cout << v[i] << ",";
    }
}
