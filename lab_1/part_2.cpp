#include "part_2.h"

void part_2(int * unsorted_array, int size)
{
    vector<int> v;
    int c;
    cout << endl << "write from array" << endl;
    for (c = 0; c <= size; ++c){
        v.push_back(unsorted_array[c]);
        cout << v[c] << ",";
    }
    cout << endl << "sorted"<< endl;

    // gnome sort Q(n^2)
    int sz = v.size();
    int i = 1;
    int j = 2;
    int temp;
    try {// start try
        while (i < sz) {
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
cout << "error out of range" << endl;
}
}
