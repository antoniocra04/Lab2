#include <iostream>
#include <chrono>
#include "List.h"
#include "fstream"
using namespace std;

List* list = new List;

void PrintList(List* list)
{
    cout << "Current list: [ ";

    ListItem* current = list->_head;

    for (int i = 0; i < list->_length; i++)
    {
        cout << current->_value << " ";
        current = current->_next;
    }

    cout << "] length: " << list->_length;

    if (list->_head == NULL)
    {
        cout << " head: NULL";
    }
    else
    {
        cout << " head: " << list->_head->_value;
    }

    if (list->_tail == NULL)
    {
        cout << " tail: NULL";
    }
    else
    {
        cout << " tail: " << list->_tail->_value;
    }
}

void MenuMessage()
{
    PrintList(list);
    cout << "Choose one action: \n1) Add item \n2) Delete item \n3) Insert item into begining \n"
        << "4) Insert item into End \n5) Insert item after \n6) Insert item before \n7) Sort \n"
        << "\nq - Quit \nYour choice: ";
}

void ModeControl(const char& mode)
{
    string enterValue = "Enter value of item inserting";
    switch (mode)
    {
        static int position;
        static int value;
        static int searchingIndex;
    case '1':
        cout << "Enter value of adding item: ";
        cin >> value;
        list->AddItem(value);
        break;
    case '2':
        PrintList(list);
        cout << endl << "Enter position of deleting item: ";
        cin >> position;
        list->DeleteItem(position);
        break;
    case '3':
        PrintList(list);
        cout << endl << enterValue << " into begining: ";
        cin >> value;
        list->InsertAtBeginng(value);
        break;
        PrintList(list);
    case '4':
        cout << endl << enterValue << " into end: ";
        cin >> value;
        list->InsertAtEnd(value);
        break;
    case '5':
        PrintList(list);
        cout << endl << enterValue << " after item: ";
        cin >> value;
        cout << "Enter the position: ";
        cin >> position;
        list->InsertAfterItem(value, position);
        break;
    case '6':
        PrintList(list);
        cout << endl << enterValue << " before item: ";
        cin >> value;
        cout << "Enter the position: ";
        cin >> position;
        list->InsertBeforeItem(value, position);
        break;
    case '7':
        cout << "List sorted" << endl;
        list->Sort();
        break;
    default:
        break;
    }
}

int main()
{
    char mode;

    MenuMessage();
    mode = cin.get();
    while (cin.get() != '\n');
    while (mode != 'q')
    {
        system("cls");
        ModeControl(mode);

        MenuMessage();

        while (cin.get() != '\n');

        if (cin.peek() != '\n')
        {
            mode = cin.get();
        }
        else
        {
            mode = '\0';
        }

    }

    return 0;
}
