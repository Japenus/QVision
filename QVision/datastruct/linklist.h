#ifndef LINKLIST_H
#define LINKLIST_H
#include"global.h"
class Node
{
public:
    int data;
    Node* next;
    Node(int val);
};

class LinkList
{
public:
    LinkList();
    ~LinkList();
public:
    void print();
    int search(int val);
    void append(int val);/*tail insert*/
    void remove(int val);
    void prepend(int val);/*head insert*/
    void update(int index, int val);
    void insert(int index, int val);
private:
    Node* head;
};

#endif // LINKLIST_H
