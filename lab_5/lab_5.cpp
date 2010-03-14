#include "lab_5.h"

/// Constructor
DataStructManager::DataStructManager(string *table, int size)
{
    for (int i = 0; i <= size; i++)
    {
        DataStruct data;
        data.key1 = rand() % size - (size/2);
        data.key2 = rand() % size - (size/2);
        data.str = table[rand() % size];
        __container.push_back(data);
    }
}

void DataStructManager::print()
{
    container_type::iterator iter;
    for(iter = __container.begin(); iter < __container.end(); iter++)
    {
        cout <<"('"<< iter->str<<"', "<< iter->key1<<", "<< iter->key2 << ")"<<endl;
    }
}

void DataStructManager::sort()
{
    DataStruct tmp;
    container_type::iterator i,j;
    for ( i = __container.begin(); i < __container.end(); i++)
    {
        for (j = __container.begin(); j < __container.end(); j++)
        {
            if( i->key1 < j->key1)
            {
                tmp = *i;
                *i = *j;
                *j = tmp;
            }
            else
            {
                if(i->key1 == j->key1)
                {
                    if(i->key2 < j->key2)
                    {
                        tmp = *i;
                        *i = *j;
                        *j = tmp;
                    }
                    else
                    {
                        if (i->key2 == j->key2)
                        {
                            if (i->str.length() < j->str.length())
                            {
                                tmp = *i;
                                *i = *j;
                                *j = tmp;
                            }
                        }
                    }
                }
            } // ENDIF
        } // ENDFOR2
    }// ENDFOR1

}

