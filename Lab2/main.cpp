#include <iostream>
#include <chrono>
#include "List.h"
#include "fstream"
using namespace std;

List list;

void MenuMessage()
{
    cout << list << endl;
    cout << "Choose one action: \n1) Add item \n2) Delete item \n3) Insert item into begining \n"
        << "4) Insert item into End \n5) Insert item after \n6) Insert item before \n7) Sort \n"
        << "\nq - Quit \nYour choice: ";
}

void ResearchTime()
{
    int numberOfLists = 9;
    ofstream delout;
    ofstream insout;
    delout.open("output/Delete.txt");
    insout.open("output/Insert.txt");

    for (int i = 1; i < numberOfLists; i++)
    {
        List list2;
        int maxElement = pow(10, i);
        for (int j = 0; j < maxElement; j++)
        {
            list2.InsertAtEnd(j);
        }
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();

        list2.DeleteItem(maxElement);
        chrono::steady_clock::time_point end = chrono::steady_clock::now();

        // std::cout << "Delete index = " << i << "\tTime difference = "
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
        delout << maxElement << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;
        begin = chrono::steady_clock::now();

        list2.InsertAfterItem(maxElement, maxElement - 1);
        end = chrono::steady_clock::now();

        // std::cout << "Insert index = " << i << "\tTime difference = "
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
        insout << maxElement << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;
    }
    delout.close();
    insout.close();
}

void ModeControl(const char& mode)
{
    switch (mode)
    {
        static int position;
        static int value;
        static int searchingIndex;
    case '1':
        cout << "Enter value of adding item: ";
        cin >> value;
        list.AddItem(value);
        break;
    case '2':
        cout << list << endl << "Enter position of deleting item: ";
        cin >> position;
        list.DeleteItem(position);
        break;
    case '3':
        cout << list << endl << "Enter value of item inserting into begining: ";
        cin >> value;
        list.InsertAtBeginng(value);
        break;
    case '4':
        cout << list << endl << "Enter value of item inserting into end: ";
        cin >> value;
        list.InsertAtEnd(value);
        break;
    case '5':
        cout << list << endl << "Enter value of item inserting after item: ";
        cin >> value;
        cout << "Enter the position: ";
        cin >> position;
        list.InsertAfterItem(value, position);
        break;
    case '6':
        cout << list << endl << "Enter value of item inserting before item: ";
        cin >> value;
        cout << "Enter the position: ";
        cin >> position;
        list.InsertBeforeItem(value, position);
        break;
    case '7':
        cout << "List sorted" << endl;
        list.Sort();
        break;
    default:
        break;
    }
}

int main()
{
    //char mode;

    //MenuMessage();
    //mode = cin.get();
    //while (cin.get() != '\n');
    //while (mode != 'q')
    //{
    //    system("cls");
    //    ModeControl(mode);

    //    MenuMessage();

    //    while (cin.get() != '\n');

    //    if (cin.peek() != '\n')
    //    {
    //        mode = cin.get();
    //    }
    //    else
    //    {
    //        mode = '\0';
    //    }

    //}

    ResearchTime();

    return 0;
}
