#include "lab_5.h"


/* filling our vector with table
 values and keys for sorting*/
DataStruct fill(string *table, int size) //No need for tracing exceptions
{
    int key1, key2;
    DataStruct data;
    key1 = rand() % size-size/2;//why -5- because I always look 5 steps beyond ;)
    key2 = rand() % size-size/2;
    data.key1 = key1;
    data.key2 = key2;
    data.str = table[rand() % size];
    return data;
}//fill function

void print(vector<DataStruct> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout << "We have a datastruct with sorting keys "<<v[i].key1<< " and "<< v[i].key2<<endl;
        cout << "   the string is: "<<v[i].str<< endl<<"+-----------------------------+"<< endl;
    }
} // END print

vector<DataStruct> sort(vector<DataStruct> v)
{
    DataStruct tmp;
    for (int i=0;i<v.size();i++)
    {
        for (int j=0;j<v.size();j++)
        {
            if(v[i].key1<v[j].key1)
            {
                tmp=v[i];
                v[i]=v[j];
                v[j]=tmp;
            }
            else
            {
                if(v[i].key1 == v[j].key1)
                {
                    if(v[i].key2<v[j].key2)
                    {
                        tmp=v[i];
                        v[i]=v[j];
                        v[j]=tmp;
                    }
                    else
                    {
                        if (v[i].key2==v[j].key2)
                        {
                            if (v[i].str.length()<v[j].str.length())
                            {
                                tmp=v[i];
                                v[i]=v[j];
                                v[j]=tmp;
                            }
                        }
                    }
                }
            } // ENDIF
        } // ENDFOR2
    }// ENDFOR1
    return v;
}//sort function
