#ifndef FACTORIAL_H
#define FACTORIAL_H
#include <vector>
/** @addtogroup lab_4
  @{ */
typedef std::vector<int> container_type;
typedef container_type::iterator container_iterator_type;

class Factorial
{
public:
    /// Defaut constructor. \a n is \e 10.
    Factorial(void);
    /** Alternate constructor \a n - the number of iterations*/
    Factorial(int n);
    /// Destructor
    ~Factorial(void);
    /** get begin of the #__container
      @return #container_iterator_type iterator
      */
    container_iterator_type begin(void);
    /** get end of the #__container
      @return #container_iterator_type iterator
      */
    container_iterator_type end(void);
    /// calculates factorial
    int get_f(int num);
    /// moving through #__container
    void operator()(container_iterator_type v);
private:
    container_type __container;
};
/// @}
#endif // FACTORIAL_H
