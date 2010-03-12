#include "factorial.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Factorial::Factorial(int n)
{
    container_iterator_type v;
    for(int i=0;i<n;i++)
    {
        __container.push_back(rand()%10);
    }
    cout << "Your array:" << endl;
    for(v=__container.begin(); v != __container.end(); v++)
    {
        cout << *v << endl;
    }
}
//returns begin of the vector
container_iterator_type Factorial::begin()
{
    return __container.begin();
}
//returns end of the vector
container_iterator_type Factorial::end()
{
    return __container.end();
}
//calculates factorial
int Factorial::get_f(int num)
{
    if (num == 1)
    {
        return 1;
    } else {
        return get_f(num - 1) * num;
    }
}

//moving through vector
void Factorial::operator()(container_iterator_type v)
{
    cout << *v <<" : " << get_f(*v) << endl;
}

