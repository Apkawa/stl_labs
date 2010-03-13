#include "lab_3_part_2.h"

void lab_3_part_2(void){
    // Generate <list> from rand int 1 to 20
    cout<<"test generate list"<< endl;
    int size_array[] = {0, 1, 2, 3, 4, 5, 7, 14};
    for (unsigned int i=0; i<sizeof(size_array)/sizeof(size_array[0]); i++) {
        list<int> l = random_range(size_array[i], 1, 20);
        print_list(l);
        l.clear();
    }
    cout << endl<< "create task random list" << endl;
    list<int> l = random_range(15, 1, 20);

    print_list(l);
    // print list as
    // 12345678 -> 18273645
    cout << "special print"<< endl;
    special_print(l);
}

template <typename T> T randint(T a, T b){
    return ((b-a)*((T)rand()/RAND_MAX))+a;
}

void print_list(list<int> v){
    list<int>::iterator iter;
    cout << "[ ";
    for (iter=v.begin(); iter != v.end(); ++iter){
        cout << *iter <<", ";
    }
    cout << "] len: "<< v.size() << endl;

}


list<int> random_range(int size, int a, int b){
    list<int> l;
    int r;
    for (int i = 0; i < size; i++){
        r = (int) randint<double> (a, b);
        //cout << r << endl;
        l.push_back(r);

    }
    //print_list(l);
    return l;
}

void special_print(list<int> l){
    // not work on num % 2 != 0
    list<int>::iterator iter = l.begin();
    list<int>::reverse_iterator rev_iter = l.rbegin();
    list<int> tmp;

    for (;; ++iter, ++rev_iter){
        tmp.push_back(*iter);
        if(tmp.size() >= l.size()){
            break;
        }
        tmp.push_back(*rev_iter);
    }
    print_list(tmp);
}
