#ifndef QUEUEWITHPRIORITY_H
#define QUEUEWITHPRIORITY_H
#include <list>
#include <string>
#include <iostream>

typedef enum {
    LOW,
    NORMAL,
    HIGH } ElementPriority;

struct QueueElement {
    ElementPriority priority;
    std::string name;
    friend bool operator<(const QueueElement &left_e, const QueueElement &right_e){
        return (left_e.priority < right_e.priority);
    }

};

typedef std::list<QueueElement> __queue_type;
typedef std::list<QueueElement>::iterator __queue_iterator_type;
class QueueWithPriority
{
private:
    __queue_type __queue;
public:
    QueueWithPriority(void);
    ~QueueWithPriority(void);
    void putElement(const QueueElement &element, ElementPriority priority);
    QueueElement getElement(void);
    void accelerate(void);
    void print_queue(void);

    // overloaded
//    friend ostream& operator<<(ostream &ostr, const QueueWithPriority &obj)

};

//ostream& QueueWithPriority::operator<<(ostream &ostr, const QueueWithPriority &obj){
//    ostr<<obj;
//    return ostr;
//}


#endif // QUEUEWITHPRIORITY_H
