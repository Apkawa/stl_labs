#include <iostream>
#include <vector>
#include <stdexcept>
#ifdef _WIN32_C_LIB
    #include <cstdio>
#endif //WIN32

#define get_size_array(array) sizeof(array) / sizeof(array[0])
using namespace std;

void part_2();

int unsorted_array[] = {3, 23, 6, 7, 9, 0, 48, 3, 4, 5, 7, 8};

int main(int argc, char *argv[])
{
    part_2();
#ifdef _WIN32_C_LIB
    getchar();
#endif //WIN32
    return 0;
}

void part_2(void){
    vector<int> v;
    int c;
    cout << "write from array\n";
    for (c = 0; c < get_size_array(unsorted_array); ++c){
        v.push_back(unsorted_array[c]);
        cout << v[c] << ",";
    }
    cout << "\nsorted\n";

    // gnome sort Q(n^2)
    int size = v.size();
    int i = 1;
    int j = 2;
    int temp;
    try {// start try
        while (i < size) {
            if ( v.at(i-1) <= v.at(i)){
                i = j;
                j++;
            } else {
                //swap
                temp = v.at(i);
                v.at(i) = v.at(i-1);
                v.at(i-1) = temp;
                //endswap
                i--;
                if (i == 0){
                    i = j;
                    j++;
                }
            }
        }
        for (i=0; i < v.size(); ++i) {
            cout << v.at(i) << ",";
        }
} // end try
catch(out_of_range){
cout << "error out of range\n";
}
}
