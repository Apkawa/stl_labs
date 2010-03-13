#include "part_3.h"
void part_3(int * unsorted_array, int size){
    vector<int> v;
    int i;
    cout << endl << "write from array" << endl;
    for (i = 0; i < size; ++i){
        v.push_back(unsorted_array[i]);
        cout << v[i] << ",";
    }
    cout <<endl<< "sorted"<< endl;

    // paste sort method Q(n^2)
    vector<int>::iterator iter;
	bool flag = true;
	int tmp;
	while(flag)
	{
		flag = false;
		for (iter = v.begin(); iter < --v.end(); iter++)
		{
			if ( *iter > *(iter+1) )
			{
                // swap
				tmp = *iter;
				*iter = *(iter+1);
				*(iter+1) = tmp;
				flag = true;
			}
		}
	}
    //end sort

    for (i=0; i < v.size(); ++i) {
        cout << v[i] << ",";
    }
}
