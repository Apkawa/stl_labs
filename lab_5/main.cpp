#include "lab_5.h"
#include "../lab_helper.h"

#define SIZE 10

int main(void)
{
    vector<DataStruct> data;
    DataStruct tmp;
    string arr[SIZE];

    read_file(arr, "input.txt", SIZE);
    for (int i = 0; i < get_size(arr); i++)
    {
        tmp = fill(arr, SIZE);
        data.push_back(tmp);
    }
    print(data);
    cout << endl << endl <<"+=================Sorting================+"<< endl << endl;
    data = sort(data);
    print(data);

    win32cmd();
    return EXIT_SUCCESS;
}
