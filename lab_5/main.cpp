/** @defgroup lab_5 Lab 5
  @{ */
/** @page lab_5 Lab 5: algoritm-sort
Выполнить ВСЕ задания

-# Написать программу, которая выполняет следующие действия:
    -# Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным образом в диапазоне от -5 до 5, str заполняется из таблицы (таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
    -# Выводит полученный вектор на печать
    -# Сортирует вектор следующим образом:
        -# По возрастанию key1
        -# Если key1 одинаковые, то по возрастанию key2
        -# Если key1 и key2 одинаковые, то по возрастанию длинны строки str
-# Выводит полученный вектор на печать

DataStruct определена следующим образом:
@code
typedef struct
{
    int       key1;
    int       key2;
    string  str;
} DataStruct;
@endcode
  */

/// @}
#include "lab_5.h"
#include "../lab_helper.h"

#define SIZE 10

int main(void)
{

    string arr[SIZE];

    read_file(arr, "input.txt", SIZE);
    DataStructManager dm(arr, SIZE);
    dm.print();
    cout << endl << endl <<"+=================Sorting================+"<< endl << endl;
    dm.sort();
    dm.print();

    win32cmd();
    return EXIT_SUCCESS;
}
