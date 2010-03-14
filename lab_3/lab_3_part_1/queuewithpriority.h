/**
    @defgroup lab_3_part_1 Part 1
    @ingroup lab_3
    @{
*/
#ifndef QUEUEWITHPRIORITY_H
#define QUEUEWITHPRIORITY_H
//#define _HAS_ITERATOR_DEBUGGING 0
#include <list>
#include <string>
#include <iostream>
using namespace std;

typedef enum
{
    LOW,
    NORMAL,
    HIGH } ElementPriority;

/** QueueElement structure */
struct QueueElement
{
    /// Priority enum #ElementPriority
    ElementPriority priority;
    /// Element name
    string name;
    /** Default constructor */
    QueueElement(string _name, ElementPriority _priority);
    /** Alternate constructor */
    QueueElement(char _name[], ElementPriority _priority);
    /** Overload < for sort. Desperated. */
    friend bool operator<(const QueueElement &leftel, const QueueElement &rightel);
    /// Overload << for iostream
    friend ostream& operator<<( ostream &ostr, const QueueElement &L );
};

/// Container type for #QueueWithPriority
typedef list<QueueElement> __queue_type;
/// Container iterator type for #QueueWithPriority
typedef __queue_type::iterator __queue_iterator_type;
/// Container reverse iterator type for #QueueWithPriority
typedef __queue_type::reverse_iterator __queue_reverse_iterator_type;

/** QueueWithPriority container for QueueElement */
class QueueWithPriority
{
private:
    __queue_type __queue;
public:
    /// Constructor
    QueueWithPriority(void);
    /// Desctructor
    ~QueueWithPriority(void);
    /// put #QueueElement
    void putElement(const QueueElement &element);
    /// put char name[] and #ElementPriority priority
    void putElement(const char name[], ElementPriority priority);
    /// return first #QueueElement
    QueueElement getElement(void);
    /// accelerate - set all #QueueElement priority to HIGH and move afrer HIGH elements and before  NORMAL elements
    void accelerate(void);
    /// return #__queue size
    int size(void){
        return __queue.size();
    }
    /// for human print #QueueWithPriority
    void print_queue(void);

};
/** @} */

#endif // QUEUEWITHPRIORITY_H
