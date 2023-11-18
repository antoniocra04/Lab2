#pragma once

struct ListItem 
{
	ListItem* _next;
	ListItem* _prev;
	int _value;

	ListItem();
};