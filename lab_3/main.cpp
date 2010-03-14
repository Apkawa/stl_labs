/** @defgroup lab_3 Lab 3
  @{ */
/**
@page lab_3 Lab 3: list-deque
@section lab_3_part_1 Часть 1
Ниже приведен интерфейс класса очереди с приоритетами, который функционирует следующим образом.

В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из трех уровней приоритета (low, normal, high)

Элементы из очереди извлекаются в соответствии с их приоритетами (сначала извлекаются элементы с приоритетом high, потом normal, потом low), элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления.

В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся в момент акселерации в очереди увеличивают свой приоритет до high и «обгоняют» элементы с приоритетом normal.

Ниже приведен интерфейс этого класса:
@code
typedef enum
{
    LOW,
    NORMAL,
    HIGH
} ElementPriority;

typedef struct
{
    string name;
} QueueElement;

class QueueWithPriority
{
    // Конструктор, создает пустую очередь
   QueueWithPriority();

    // Деструктор
   ~QueueWithPriority();

    // Добавить в очередь элемент element с приоритетом priority
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);

    // Получить элемент из очереди
    // метод должен возвращать элемент с наибольшим приоритетом, который был
    // добавлен в очередь раньше других
    QueueElement GetElementFromQueue();

    // Выполнить акселерацию
    void Accelerate();
};
@endcode
Реализовать этот класс, используя list или deque. Объяснить свой выбор.
Протестируете программу, добавьте отладочный вывод, показывающий, что  класс работает правильно.

@section lab_3_part_2 Часть 2
Разработайте программу, которая

- Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
- Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.

Например если список содержит:
@pre 1 2 3 4 5 6 7 8
то вывод будет иметь вид
@pre 1 8 2 7 3 6 4 5

Подсказка: можно использовать рекурсию и двунаправленные итераторы
*/
/** @} */
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
