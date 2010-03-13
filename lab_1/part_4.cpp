#include "part_4.h"

void part_4(char filename[]){
    FILE * f;
    f = fopen(filename, "rb");
    if (f == NULL){
        cout << "fail open file: " << filename << endl;
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

    //
    vector<char *> v(res, res+lines); // load all lines in vector
    //

    // print vector.
    for (i=0; i<v.size();i++){
        cout << v[i];

    }
}
