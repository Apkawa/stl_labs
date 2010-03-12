#ifndef FACTORIAL_H
#define FACTORIAL_H
#include <vector>

typedef std::vector<int> container_type;
typedef std::vector<int>::iterator container_iterator_type;

class Factorial
{
public:
    /*n- the number of iterations*/
    Factorial(int n);
    //~Factorial(void);
    //returns begin of the vector
    container_iterator_type begin(void);
    //returns end of the vector
    container_iterator_type end(void);
    //calculates factorial
    int get_f(int num);
    //moving through vector
    void operator()(container_iterator_type v);
private:
    container_type __container;
};

#endif // FACTORIAL_H
