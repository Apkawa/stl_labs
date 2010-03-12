#include <cstdlib>
#include <time.h>
#include "factorial.h"
#include "../lab_helper.h"
using namespace std;

int main(void)
{
    Factorial f(10);
    f(f.begin() + 6);
    win32cmd();
    return EXIT_SUCCESS;
}
