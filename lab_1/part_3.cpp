#include "part_3.h"
void part_3(int * unsorted_array, int size){
    vector<int> v;
    int i;
    cout << endl << "write from array" << endl;
    for (i = 0; i <= size; ++i){
        v.push_back(unsorted_array[i]);
        cout << v[i] << ",";
    }
    cout <<endl<< "sorted"<< endl;

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
