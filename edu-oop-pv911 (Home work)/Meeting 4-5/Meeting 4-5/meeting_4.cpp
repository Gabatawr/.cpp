#include "header.h"
#include "House.h"

/**
 * Тема:
 *   Указатель this. Побитовое копирование.  Конст­руктор копирования.
 *   
 * Задание:
 *   Создайте программу, имитирующую многоквартирный дом.
 *   
 *   Необходимо иметь классы “Человек”, “Квартира”, “Дом”.
 *   Класс “Квартира” содержит динамический массив объектов класса “Человек”.
 *   Класс “Дом” содержит массив объектов класса “Квартира”.
 *   
 *   Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области класса.
 *   Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для ФИО в классе “Человек”.
 *   Не забывайте обеспечить классы различными конструкторами (конструктор копирования обязателен), деструкторами.
 *   В main протестировать работу полученного набора классов.
 */

void meeting_4()
{
    do {

        House GABTower;

        GABTower.print();
    	
    } while (restart());
}