/**
  @defgroup lab_2 Lab 2
  @{
*/
/** @page lab_2 Lab 2: string
Разработать программу, которая должна сделать следующее:
-# Прочитать содержимое текстового файла. Файл может содержать:
    - Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
    - Знаки препинания – «.», «,» «!» «?» «:» «;»
    - Пробельные символы – пробел, табуляция, символ новой строки.
-# Отформатировать текст следующим образом:
    - Не должно быть  пробельных символов отличных от пробела
    - Не должно идти подряд более одного пробела
    - Между словом и знаком препинания не должно быть пробела
    - После знака препинания всегда должен идти пробел
    - Слова длиной более 10 символов заменяются на слово «Vau!!!»
-# Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно целиком находиться в строке) и ее длинна не превышает 40 символов.

Подсказки:
- Для хранения всего входного текста можно использовать одну строку
- Можно создать строки содержащие символы принадлежащие какое либо категории, например знаки препинания
- Для хранения результирующих строк можно использовать vector<string>

  */
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>


using namespace std;

/// read file function
string read_file(char * filename);

/**
  Cleaned string of [^\w\ \,\.] and replace [\s]{2,} => \s
  replace word [\w]{10,} => "Vau!!!"
  @return cleaned string \c string
  */
string str_clean(string str);

/// Print vercor template function
template <typename T> void print_vector(vector<T> v);

/**
  * pretty print function
  * @param width an \c int for set width print
  */
void pretty_print(string str, int width);


int main(int argc, char *argv[])
{
    char filename[] = "input.txt";
    string s = read_file(filename);
    //cout << s;
    s = str_clean(s);
    //cout << s;
    pretty_print(s, 40);

#ifdef _WIN32_C_LIB
    getchar();
#endif //WIN32

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
     or
     str.remove(QRegExp("[^\\w\ \,\.]"));
     str.replace(QRegExp("[\\s]{2,}"),"\\s");
     or
     str = str.simplified();
     */
    unsigned int pos;
    unsigned int i;
    char * not_other_space_char[] = {"\a","\b","\n","\t","\v","\r","\f", "  "};
    char replace_word[] = "Vau!!!"; //bullshit

    for (i=0; i < sizeof(not_other_space_char)/sizeof(not_other_space_char[0]); ++i){
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

    // equal str.replace(QRegExp("[\\w]{10,}"), replace_word);
    int pre_pos = 0;
    int word_size = 0;
    int dot;
    bool _loop = true;

    while (_loop){
        pos = str.find(" ", pos+1 );
        if (pos ==  str.npos) {
            _loop = false;
            pos = str.length();
        }

        if( pos != 0){
            word_size = pos-1 - pre_pos;
            if ((str.compare(pos-1, 1, ",") == 0)||((dot=str.compare(pos-1, 1, ".")) == 0)){
                word_size--;
            }

            if (word_size > 10){
                if (dot == 0){
                    word_size++;
                }
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
    unsigned int i;
    for (i = 0; i < v.size(); ++i){
        cout << v[i] <<"\n";
    }
}


void pretty_print(string str, int width){
    vector<string> str_v;
    unsigned int last_pos = 0;
    unsigned int max_pos = str.size();
    unsigned int end = 0;
    unsigned int offset = 0;
    unsigned int line_width;

    while (true){
        line_width = width;
        end = last_pos+line_width;

        if (!(last_pos+line_width >= max_pos)) {
            offset = str.rfind(" ", end);
            if (offset != str.npos){
                line_width = line_width - (end - offset);
            }
        }

        str_v.push_back(str.substr(last_pos + 1, line_width));
        last_pos = last_pos + line_width;
        if (last_pos >= max_pos){
            break;
        }

    }
    print_vector<string>(str_v);

}
/// @}
