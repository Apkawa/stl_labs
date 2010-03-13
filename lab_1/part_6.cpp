#include "part_6.h"

void part_6(void){
    int size_array[] = {5, 10, 25, 50, 100};
    unsigned int i;
    for (i = 0; i <= get_size_array(size_array); ++i){
        cout << "array size: "<< size_array[i]<< endl;
        double *da;
        da = (double *) calloc(size_array[i], sizeof(double));
        full_random(da, size_array[i]);
        vector<double>v(da, da+size_array[i]);
        cout <<"unsorted vector" << endl;
        print_vector<double>(v);
        cout << endl;
        cout <<"sorted vector" << endl;
        print_vector<double>(sort_vector<double>(v));
        cout << endl;
        free(da);
    }
}
template <typename T> void print_array(T array[], int size) {
    int i;
    cout << "[";
    for (i = 0; i < size; ++i){
        cout << array[i] <<", ";
    }
    cout << "]"<< endl;

}

template <typename T> void print_vector(vector<T> v){
    unsigned int i;
    cout << "[ ";
    for (i = 0; i < v.size(); ++i){
        cout << v[i] <<", ";
    }
    cout << "]"<< endl;
}


template <typename T> T rand_range(T a, T b){
    return ((b-a)*((T)rand()/RAND_MAX))+a;
}

void full_random(double *array, int size){
    int i;
    for (i = 0; i < size; ++i){
        array[i] = rand_range<double>(-1.0, 1.0);
    }
}

template <class T> vector<T> sort_vector(vector<T> v){
    unsigned int i;
    bool t = true;
    T temp;
    while (t){
        t = false;
        for (i=0; i < v.size() - 1; i++){
            if (v[i] > v[i+1]){
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                t = true;
            }
        }
    }
    return v;
}
