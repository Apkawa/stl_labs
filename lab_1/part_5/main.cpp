#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>
#define DEBUG false
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vec;
    cout << "Enter any number. 0 - exit\n";
    if (!DEBUG){
        int n;
        while(true){
            scanf("%d",&n);
            if (n == 0){
                cout << "ZERO! Boky wa Lelush vi Britania!\n";
                break;
            }

            vec.push_back(n);
            cout << "Ok, entering number "<< n << "\n";
        }
    } else {
        int i;
        int ia[] = {10,100,9,9,2, 9*9, 25,20,2};
        for (i=0; i <sizeof(ia)/sizeof(ia[0]); i++){
            vec.push_back(ia[i]);
        }
    }

    vector<int>::iterator iter;
    bool insert_f = false;
    //cout << *(vec.end()-1);
    if (*(vec.end()-1) == 2) {
        insert_f = true;
    }
    for (iter = vec.begin(); iter < vec.end(); iter++){
        //cout << *iter  << "\n";
        if (*iter % 2 == 0){
            iter = vec.erase(iter);
            iter--;
        }
    }

    int _i;
    if (insert_f) {
        for (iter = vec.begin(); iter < vec.end(); iter++){
            if (*iter % 3 == 0){
                for (_i=0; _i < 3; ++_i){
                    iter = vec.insert(iter+1, 1);
                }
            }
        }
    }

    for (iter = vec.begin(); iter < vec.end(); iter++){
        cout << *iter  << ",";
    }

    cout << endl;

    return 0;
}
