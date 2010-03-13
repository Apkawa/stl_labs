#ifndef LAB_HELPER_H
#define LAB_HELPER_H

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

#define get_size(array) sizeof(array)/sizeof(array[0])

using namespace std;

int read_file(string arr[], char file[], int size)
{
    ifstream myfile(file);
    if (myfile.is_open())
    {
    int i=0;
    string temp;
        while ((! myfile.eof() )&&(i<size))
        {
            getline(myfile, arr[i]);
            i+=1;
        }
        myfile.close();
    return 0;
    }
    else
    {
        cout << "Unable to open file";
    return 1;
    }
}

//string read_file(char * filename){
//        FILE * f;
//
//        char * f_buf;
//        long int f_size;
//
//        f = fopen(filename, "r");
//        if (f == NULL){
//            cerr << "fail open file "<< filename;
//            return NULL;
//        }
//        fseek(f, 0, SEEK_END);
//        f_size = ftell(f);
//        rewind(f);
//        f_buf = (char *) malloc(f_size * sizeof(char));
//        if (fread(f_buf, sizeof(char), f_size, f) != f_size){
//            cerr << "read file failure" << endl;
//        }
//        fclose(f);
//        string content(f_buf, f_size);
//        free(f_buf);
//        return content;
//    }

void win32cmd(void){
#ifdef _WIN32_C_LIB
getchar();
#endif //WIN32
}

#endif // LAB_HELPER_H
