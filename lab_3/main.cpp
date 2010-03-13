#include <iostream>
#include <cstdlib>

#include "../lab_helper.h"
#include "lab_3_part_1/queuewithpriority.h"
#include "lab_3_part_2/lab_3_part_2.h"

using namespace std;

int main(void)
{
    cout << "============ Part 1 ============="<< endl;

    cout << "Test class" << endl;
    QueueWithPriority queue;
    QueueElement qe("l_nya1", LOW);
    queue.putElement(qe);
    queue.putElement(QueueElement("n_nya1", NORMAL));
    queue.putElement("n_nya2", NORMAL);
    queue.putElement("h_nya1", HIGH);
    queue.putElement("h_nya2", HIGH);
    queue.putElement("n_nya3", NORMAL);
    queue.putElement("h_nya3", HIGH);
    queue.putElement("l_nya2", LOW);

    queue.print_queue();
    cout << queue.getElement() << endl;

    cout << "=== accellerate ===" << endl;
    queue.accelerate();
    queue.print_queue();
    cout << queue.getElement() << endl;
    cout << queue.getElement() << endl;

    cout << "============ Part 2 ============="<< endl;
    lab_3_part_2();
    win32cmd();
    return EXIT_SUCCESS;
}
