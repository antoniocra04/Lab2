#pragma once
#include "ListItem.h"
#include <iostream>

using std::ostream;

class List 
{
private:
	ListItem* _head;
	ListItem* _tail;
	int _length;

	/// <summary>
	/// Найти элемент по позиции
	/// </summary>
	/// <param name="position">Позиция элемента</param>
	/// <returns>List</returns>
	ListItem* FindItem(const int& position);

	/// <summary>
	/// Найти элемент по значению
	/// </summary>
	/// <param name="value">Значение элемента</param>
	/// <returns>List</returns>
	ListItem* FindItemByValue(const int& value);

	/// <summary>
	/// Поменять элементы местами
	/// </summary>
	/// <param name="firstPosition">Позиция первого</param>
	/// <param name="secondPosition">Позиция второго</param>
	void Swap(int firstPosition, int secondPosition);

public:
	List();
	~List();

	/// <summary>
	/// Добавление элемента в список
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>List</returns>
	List& AddItem(const int& value);

	/// <summary>
	/// Удаление элемента
	/// </summary>
	/// <param name="value">значение элемента</param>
	/// <returns>List</returns>
	List& DeleteItem(const int& value);

	/// <summary>
	/// Вставка элемента в начало
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>List</returns>
	List& InsertAtBeginng(const int& value);

	/// <summary>
	/// Вставка элемента в конец
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>List</returns>
	List& InsertAtEnd(const int& value);

	/// <summary>
	/// Вставка элемента после какого-либо элемента
	/// </summary>
	/// <param name="value">значение</param>
	/// <param name="afterValue">значение элемента после которым нужно вставить новый</param>
	/// <returns>List</returns>
	List& InsertAfterItem(const int& value, const int& afterValue);

	/// <summary>
	/// Вставка элемента перед каким-либо элементом
	/// </summary>
	/// <param name="value">значение</param>
	/// <param name="beforeValue">значение элемента перед которым нужно вставить новый</param>
	/// <returns>List</returns>
	List& InsertBeforeItem(const int& value, const int& beforeValue);

	/// <summary>
	/// Сортировка
	/// </summary>
	/// <returns>List</returns>
	List& Sort();


	friend ostream& operator<<(ostream& os, List& list);
	
};