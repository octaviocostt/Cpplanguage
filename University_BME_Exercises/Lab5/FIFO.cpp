#include "FIFO.h"
#include <iostream>

using namespace std;

FIFO::FIFO()
{
	rear = NULL;
	front = NULL;
}

void FIFO::insert()
{
    node* temp;
    temp = new node;
    cout << "Data :"<<endl;
    cin >> temp->data;
    temp->next = NULL;
    cout << "---------------------------" << endl;
    if (rear == NULL)
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void FIFO::delet()
{
    if (front != NULL)
    {
        node* temp = front;
        cout <<  " Deleted \n" << front->data << endl;
        front = front->next;
        delete temp;
        if (front == NULL)
            rear = NULL;
    }
    else
        cout << "Queue Empty.." <<endl;
}

void FIFO::print()
{
    node* temp = front;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << "---------------------------" << endl;
}

FIFO::~FIFO()
{
    while (front != NULL)
    {
        node* temp = front;
        front = front->next;
        delete temp;
    }
}
