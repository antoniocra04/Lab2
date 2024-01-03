#include <iostream>
#include "List.h"

List::List() 
{
	_head = nullptr;
	_tail = nullptr;
	_length = 0;
}

ListItem* List::FindItem(const int& position)
{
	if (_length == 0 || _length < position || position <= 0)
	{
		return nullptr;
	}

	ListItem* current = _head;

	for (int i = 1; i < position; i++) {
		current = current->_next;
	}
	
	return current;
}

ListItem* List::FindItemByValue(const int& value)
{
	if (_length == 0)
	{
		return nullptr;
	}

	ListItem* current = _head;

	while (current)
	{
		if (current->_value == value)
		{
			return current;
		}

		current = current->_next;
	}

	return nullptr;
}

List& List::AddItem(const int& value)
{
	ListItem* newItem = new ListItem;
	newItem->_prev = _tail;
	newItem->_value = value;

	if (_tail != nullptr)
	{
		_tail->_next = newItem;
		_tail = newItem;
	}
	else
	{
		_head = newItem;
		_tail = newItem;
	}

	_length += 1;

	return *this;
}

List& List::InsertAtBeginng(const int& value)
{
	ListItem* newItem = new ListItem;
	newItem->_next = _head;
	newItem->_value = value;

	if (_head != nullptr)
	{
		_head->_prev = newItem;
		_head = newItem;
	}
	else
	{
		_head = newItem;
		_tail = newItem;
	}

	_length += 1;

	return *this;
}

List& List::InsertAtEnd(const int& value)
{
	AddItem(value);
	return *this;
}

List& List::InsertAfterItem(const int& value, const int& afterValue)
{
	if (_length < 1) {
		return *this;
	}

	ListItem* prev = FindItemByValue(afterValue);
	ListItem* next = prev->_next;

	ListItem* newItem = new ListItem;
	newItem->_next = next;
	newItem->_prev = prev;
	newItem->_value = value;

	_length += 1;

	if (prev != nullptr)
	{
		prev->_next = newItem;
	}

	if (next != nullptr)
	{
		next->_prev = newItem;
	}
	else
	{
		_tail = newItem;
	}

	return *this;
}

List& List::InsertBeforeItem(const int& value, const int& beforeValue)
{
	if (_length < 1) {
		return *this;
	}

	ListItem* next = FindItemByValue(beforeValue);
	ListItem* prev = next->_prev;

	ListItem* newItem = new ListItem;
	newItem->_next = next;
	newItem->_prev = prev;
	newItem->_value = value;

	_length += 1;

	if (prev != nullptr)
	{
		prev->_next = newItem;
	}
	else
	{
		_tail = newItem;
	}

	if (next != nullptr)
	{
		next->_prev = newItem;
	}

	return *this;
}

List& List::DeleteItem(const int& value)
{
	if (_length < 1) {
		return *this;
	}

	ListItem* element = FindItemByValue(value);

	if (element == nullptr)
	{
		return *this;
	}

	if (element->_next == nullptr)
	{
		_tail = element->_prev;
	}
	else if (element->_prev == nullptr)
	{
		_head = element->_next;
	}

	if (element->_prev != NULL)
	{
		element->_prev->_next = element->_next;
	}

	if (element->_next != NULL)
	{
		element->_next->_prev = element->_prev;
	}

	_length = _length - 1;

	if (_length == 0)
	{
		_head = nullptr;
		_tail = nullptr;
	}

	delete element;

	return *this;
}

void List::Swap(int firstPosition, int secondPosition)
{
	if (firstPosition == 0 || secondPosition == 0 || firstPosition == secondPosition) return;

	if (firstPosition > secondPosition)
	{
		int temp = firstPosition;
		firstPosition = secondPosition;
		secondPosition = temp;
	}

	ListItem* first = FindItem(firstPosition);
	ListItem* second = FindItem(secondPosition);

	if (first == _head)
	{
		_head = second;
	}
	else if (second == _head)
	{
		_head = first;
	}
	if (first == _tail)
	{
		_tail = second;
	}
	else if (second == _tail)
	{
		_tail = first;
	}

	ListItem* temp;
	temp = first->_next;
	first->_next = second->_next;
	second->_next = temp;

	if (first->_next != NULL)
	{
		first->_next->_prev = first;
	}
	if (second->_next != NULL)
	{
		second->_next->_prev = second;
	}

	temp = first->_prev;
	first->_prev = second->_prev;
	second->_prev = temp;

	if (first->_prev != NULL)
	{
		first->_prev->_next = first;
	}
	if (second->_prev != NULL)
	{
		second->_prev->_next = second;
	}

}

List& List::Sort()
{
	for (int i = 1; i <= _length; i++)
	{
		for (int j = 1; j <= _length; j++)
		{
			ListItem* first = FindItem(i);
			ListItem* second = FindItem(j);
			if (first->_value < second->_value)
			{
				Swap(i, j);
			}
		}
	}

	return *this;
}

List::~List() 
{
	for (int i = 1; i <= _length; i++)
	{
		DeleteItem(_head->_value);
	}
}