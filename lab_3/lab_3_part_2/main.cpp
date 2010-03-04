#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

template <typename T> T randint(T a, T b);

void print_list(list<int> v);

list<int> random_range(int size, int a, int b);

void special_print(list<int> l);

void lab_3_part_2(void);

int main(int argc, char *argv[])
{
    lab_3_part_2();
#ifdef _WIN32_C_LIB
    getchar();
#endif //WIN32
    return EXIT_SUCCESS;
}

void lab_3_part_2(void){
    // Generate <list> from rand int 1 to 20
    // test generate list
    int size_array[] = {0, 1, 2, 3, 4, 5, 7, 14};
    for (int i=0; i<sizeof(size_array)/sizeof(size_array[0]); i++) {
        list<int> l = random_range(size_array[i], 1, 20);
        print_list(l);
        l.clear();
    }


    list<int> l = random_range(14, 1, 20);
    print_list(l);
    // print list as
    // 12345678 -> 18273645
    special_print(l);


}

template <typename T> T randint(T a, T b){
    return ((b-a)*((T)rand()/RAND_MAX))+a;
}

void print_list(list<int> v){
    list<int>::iterator iter;
    int i;
    cout << "[ ";
    for (i = 0, iter=v.begin(); i < v.size(); ++i, ++iter){
        cout << *iter <<", ";
    }
    cout << "] len: "<< i << endl;

}


list<int> random_range(int size, int a, int b){
    list<int> l;
    int i;
    int r;
    for (i = 0; i < size; i++){
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
    int i;
    for (i=0; i <= (l.size()/2)-1; ++i, ++iter, ++rev_iter){
        tmp.push_back(*iter);
        tmp.push_back(*rev_iter);
    }
    print_list(tmp);
}
