#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>


using namespace std;

string read_file(char * filename);

string str_clean(string str);

template <typename T> void print_vector(vector<T> v);

void pretty_print(string str, int width);


int main(int argc, char *argv[])
{
    char * filename = "input.txt";
    string s = read_file(filename);
    //cout << s;
    s = str_clean(s);
    //cout << s;
    pretty_print(s, 40);

    return EXIT_SUCCESS;
}

string read_file(char * filename){
    FILE * f;

    char * f_buf;
    long int f_size;

    f = fopen(filename, "r");
    if (f == NULL){
        cout << "fail open file "<< filename;
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    f_size = ftell(f);
    rewind(f);
    f_buf = (char *) malloc(f_size * sizeof(char));
    if (fread(f_buf, sizeof(char), f_size, f) != f_size){
        cout << "read file failure" << endl;
    }
    fclose(f);
    string content(f_buf, f_size);
    free(f_buf);
    return content;
}

string str_clean(string str){
    /*

     #equalient
     >>> import re
     >>> re.sub(r'[^\w\.\,\s]','', str)
     */
    int pos;
    char * not_other_space_char[] = {"\a","\b","\n","\t","\v","\r","\f", "  "};
    char * replace_word = "Vau!!!"; //bullshit

    for (int i=0; i< sizeof(not_other_space_char)/sizeof(not_other_space_char[0]); ++i){
        while( (pos = str.find(not_other_space_char[i])) != str.npos ){
            str.erase(pos,1);
        }
    }
    while ((pos = str.find(" ,")) != str.npos){
        str.erase(pos,1);
    }

    pos=0;
    while ((pos = str.find(",", pos+1 )) != str.npos){
        if(str.compare(pos+1, 1, " ") == 1){
            str.insert(pos+1, " ");
        }
    }

    int pre_pos = 0;
    int word_size = 0;
    bool _loop = true;

    while (_loop){
        pos = str.find(" ", pos+1 );
        if (pos ==  str.npos) {
            _loop = false;
            pos = str.length()-1;
        }

        if( pos != 0){
            word_size = pos-1 - pre_pos;
            if ((str.compare(pos-1, 1, ".") == 0)||(str.compare(pos-1, 1, ",") == 0)){
                word_size--;
            }
            if (word_size > 10){
                str.replace(pre_pos+1, word_size, replace_word);
            }

        }
        word_size = 0;
        pre_pos = pos;
    }

    //cout << str;
    return str;
}

template <typename T> void print_vector(vector<T> v){
    int i;
    for (i = 0; i < v.size(); ++i){
        cout << v[i] <<"\n";
    }
}

/*
  * pretty print function
  */
void pretty_print(string str, int width){
    vector<string> str_v;
    int l_pos = 0;
    int max_pos = str.size();
    int start = 0;
    int end = 0;
    int line_width;
    while (true){
        start = l_pos;
        line_width = width;
        end = start+line_width+1;
        while(line_width > 0){
            if (end <= max_pos){
                if (str.compare(start+line_width, 1, " ") == 1){
                    line_width--;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        str_v.push_back(str.substr(start, line_width));
        l_pos = start+line_width+1;
        if (l_pos >= max_pos){
            break;
        }

    }

    print_vector<string>(str_v);

}
