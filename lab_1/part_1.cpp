#include "part_1.h"

void part_1(int unsorted_array[], int size){
    vector<int> v;
    int i;

    cout << "write from array\n";
    for (i = 0; i < size; ++i){
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
