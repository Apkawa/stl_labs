#include "main.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    read_textfile_to_vector("input.txt");
#ifdef _WIN32_C_LIB
    getchar();
#endif //WIN32
    return EXIT_SUCCESS;
}


void read_textfile_to_vector(char filename[]){
    FILE * f;
    f = fopen(filename, "rb");
    if (f == NULL){
        cout << "fail open file " << filename << endl;
        return;
    }

    int i=1;
    char **res;
    char *tmp;
    res = (char **) malloc(1 * sizeof(char *));
    while(!feof(f)){
        tmp = (char *) calloc(256, sizeof(char));
        fgets(tmp, 256,f);
        res[i-1] = tmp;
        i++;
        res = (char **) realloc(res, i * sizeof(char *));
    }
    int lines = i-2;
    cout << "reading "<< lines<< " lines"<< endl;

    vector<char *> v(res, res+lines); // load all lines in vector

    // print vector.
    for (i=0; i<v.size();i++){
        cout << v[i];

    }
}
