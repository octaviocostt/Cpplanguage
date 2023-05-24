#pragma once

struct node
{
    int data;
    node* next;
};

class FIFO
{
private:
    node* rear, * front;
public:
    FIFO();
    void insert();
    void delet();
    void print();
    ~FIFO();
};