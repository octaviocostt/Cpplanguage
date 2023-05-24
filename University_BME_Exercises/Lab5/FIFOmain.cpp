#include <iostream>
#include "FIFO.h"

using namespace std;

int main()
{
    FIFO obj; int op;
    do
    {
        cout << "1 - Insert\n2 - Delete\n3 - Print\n 0 - Quit " << endl;
        cin >> op;
        switch (op)
        {
        case 1: obj.insert();break;
        case 2: obj.delet();break;
        case 3: obj.print();
        }
    } while (op != 0);
	
}