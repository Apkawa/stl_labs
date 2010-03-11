#ifndef QUEUEWITHPRIORITY_H
#define QUEUEWITHPRIORITY_H
#include <list>
#include <string>
#include <iostream>

typedef enum
{
    LOW,
    NORMAL,
    HIGH } ElementPriority;

struct QueueElement
{
    ElementPriority priority;
    std::string name;
    QueueElement(std::string _name, ElementPriority _priority)
    {
        name=_name;
        priority=_priority;
    }
    QueueElement(char _name[], ElementPriority _priority)
    {
        name = std::string(_name),
        priority = _priority;
    }
    friend bool operator<(const QueueElement &leftel, const QueueElement &rightel)
    {
        return (leftel.priority < rightel.priority);
    }
    friend std::ostream& operator<<( std::ostream &ostr, const QueueElement &L )
    {
        ostr << "Q("<< L.name << "," << L.priority << ")";
        return ostr;
    }

//    friend bool operator<(const QueueElement &left_e, const QueueElement &right_e)
//    {
//        return (left_e.priority < right_e.priority);
//    }

};

typedef std::list<QueueElement> __queue_type;
typedef std::list<QueueElement>::iterator __queue_iterator_type;
typedef std::list<QueueElement>::reverse_iterator __queue_reverse_iterator_type;
class QueueWithPriority
{
private:
    __queue_type __queue;
public:
    QueueWithPriority(void);
    ~QueueWithPriority(void);
    void putElement(const QueueElement &element);
    void putElement(const char name[], ElementPriority priority);
    QueueElement getElement(void);
    void accelerate(void);
    int size(void){
        return __queue.size();
    }

    void print_queue(void);

};



#endif // QUEUEWITHPRIORITY_H
