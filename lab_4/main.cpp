/** @defgroup lab_4 Lab 4
  @{  */
/**
@page lab_4 Lab 4: iterators
Выполните ОДНО ИЗ заданий

@section part_1 Задание 1.

Напишите программу – «телефонную книжку».

Записи (имя и телефон) должны хранится в каком-либо STL-контейнере (vector или list), причем крайне желательно, чтобы от типа контейнера не зависело ничего, кроме одной строки в программе – объявления этого контейнера (указание: используйте typedef).

Программа должна поддерживать следующие операции:
- Просмотр текущей записи
- Переход к следующей записи
- Переход к предыдущей записи
- Вставка записи перед/после просматриваемой
- Замена просматриваемой записи
- Вставка записи в конец базы данных
- Переход вперед/назад через n записей.

Помните, что после вставки элемента итераторы становятся недействительными, поэтому после вставки целесообразно переставлять итератор на начало базы данных.

Постарайтесь реализовать операции вставки и замены с помощью одной и той же функции, которой в зависимости от требуемого действия передается либо обычный итератор, либо адаптер – один из итераторов вставки: void modifyRecord(iterator pCurrentRecord, CRecord newRecord).
Программа может сразу после запуска сама (без команд пользователя) заполнить  записную книжку некоторым количеством записей.


@section part_2 Задание 2.

Реализуйте следующие классы
Контейнер, который содержит значения факториала от 1! до 10!.

Интерфейс класса должен включать в себя как минимум:
- Конструктор по умолчанию
- Функцию получения итератора указывающего на первый элемент контейнера - \e begin()
- Функцию получения итератора указывающего на элемент, следующий за последним - \e end()

Доступ к элементам этого контейнера возможен только с помощью итераторов возвращаемых функциями \e begin() и \e end().

Контейнер не должен содержать в памяти свои элементы, они должны вычисляться при обращении к ним через итератор

Класс итератора для перечисления элементов этого контейнера, объекты этого класса возвращаются функциями \e begin() и \e end(). \n
Итератор должен быть двунаправленным. Итератор должен быть совместимым с STL (проверить это можно используя алгоритм copy для копирования содержимого разработанного контейнера в \e vector<int> )
  */
/// @}
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
