/**

*/
#include "queuewithpriority.h"
#include <iostream>
using namespace std;


QueueElement::QueueElement(string _name, ElementPriority _priority)
{
    name=_name;
    priority=_priority;
}

QueueElement::QueueElement(char _name[], ElementPriority _priority)
{
    name = string(_name),
    priority = _priority;
}

bool operator<(const QueueElement &leftel, const QueueElement &rightel)
{
    return (leftel.priority < rightel.priority);
}

ostream& operator<<( ostream &ostr, const QueueElement &L )
{
    char *priority_name;
    switch (L.priority)
    {
    case LOW: priority_name = "LOW";
        break;
    case NORMAL: priority_name = "NORMAL";
        break;
    case HIGH: priority_name = "HIGH";
        break;
    default: priority_name = "None";
    }

    ostr << "Q("<< L.name << "," << priority_name << ")";
    return ostr;
}

/// Constructor
QueueWithPriority::QueueWithPriority()
{

}
/// Destructor
QueueWithPriority::~QueueWithPriority()
{

}

void QueueWithPriority::putElement(const QueueElement &element)
{
    __queue_iterator_type iter;
    int check;
    bool insert = false;
    if ((!__queue.empty()) & (element.priority != LOW))
    {
        for(iter=__queue.begin(); iter != __queue.end(); iter++)
        {
            check = iter->priority - element.priority;
            if (check == -1)
            {
                __queue.insert(iter, element);
                insert = true;
                break;
            }
        }
        if (!insert)
        {
            __queue.push_front(element);
        }
    } else {
        __queue.push_back(element);
    }
}

void QueueWithPriority::putElement(const char name[], ElementPriority priority)
{
    putElement(QueueElement(name, priority));
}

QueueElement QueueWithPriority::getElement()
{
    if (!__queue.empty())
    {
        QueueElement qe = __queue.front();
        __queue.pop_front();
        return qe;
    } else {
        cerr << "No more QueueElement in QueueWithPriority!"<< endl;
        throw "fail";
    }

}

void QueueWithPriority::accelerate()
{
    __queue_iterator_type iter;
    __queue_iterator_type first_iter;
    bool is_low = false;

    for(iter=--__queue.end();; iter--)
    {
        if (iter->priority == LOW)
        {
            iter->priority = HIGH;
            first_iter = iter;
            is_low = true;
        }
        if ( iter == __queue.begin())
        {
            break;
        }
    }// END for

    if (is_low)
    {
        for (iter = __queue.begin(); iter != __queue.end(); iter++)
        {
            if (iter->priority == NORMAL)
            {
                __queue.splice(iter, __queue, first_iter, __queue.end());
                break;
            }// END IF
        }
    }// END IF is_low
} // END accelerate

void QueueWithPriority::print_queue()
{
    __queue_iterator_type iter;
    cout << "[";
    for(iter=__queue.begin(); iter != __queue.end();iter++)
    {
        cout<< *iter<< ",";
    }
    cout << "]" << endl;
}
/** */
