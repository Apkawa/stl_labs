#include "main.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    read_textfile_to_vector("input.txt");
    //cout << sizeof(res)/sizeof(res[0]);

}

void read_textfile_to_vector(char filename[]){
    FILE * f;
    f = fopen(filename, "rb");

    int i=1;
    char s[100];
    while(!feof(f)){
        fgets(s, 254,f);
        i++;
    }
    fseek(f, 0, SEEK_SET);

    int size = i-1;
    char *res[size];
    char *tmp;
    for (i=0; i < size; i++){
        tmp = (char *) malloc(256*sizeof(char));
        fgets(tmp, 255, f);
        res[i] = tmp;
        //cout << res[i];
    }
    //cout << sizeof(res)/sizeof(res[0]);

    vector<char *> v(res, res+sizeof(res)/sizeof(res[0]));
    //cout << v[0];
    for (i=0; i<v.size();i++){
        cout << v[i];

    }
}
