#include "linklist.h"

Node::Node(int val)
{
    data=val;
    next=nullptr;
}

LinkList::LinkList():head(nullptr){}

void LinkList::prepend(int val)
{
    Node* element = new Node(val);
    element->next = head;
    head = element;
}

void LinkList::append(int val)
{
    Node *element=new Node(val);
    if(!head){
        head=element;
    }else{
        Node *current=head;
        while(current->next){
            current=current->next;
        }
        current->next=element;
    }
}

int LinkList::search(int val)
{
    Node* cur=head;
    int index=0;
    while(cur&&cur->data!=val){
        cur=cur->next;
        index++;
    }

    if(cur){
        return index;
    }else{
        return -1;
    }
}

void LinkList::remove(int val)
{
    Node* cur=head;
    Node* prev=nullptr;
    while(cur&&cur->data!=val){
        prev=cur;
        cur=cur->next;
    }
    if(cur){
        if(prev){
            prev->next=cur->next;
        }else{
            head=cur->next;
        }
        delete cur;
    }
}

void LinkList::update(int index, int val)
{
    Node* cur=head;
    for(int i=0;i<index&&cur;i++){
        cur=cur->next;
    }
    if(cur){
        cur->data=val;
    }
}

void LinkList::insert(int index, int val)
{
    Node *element=new Node(val);
    if(index==0){
        element->next=head;
        head=element;
    }else{
        Node* cur=head;
        for(int i=0;i<index-1&&cur;i++){
            cur=cur->next;
        }
        if(cur){
            element->next=cur->next;
            cur->next=element;
        }
    }
}


void  LinkList::print()
{
    Node* cur=head;
    while(cur){
        qInfo()<<cur->data;
        cur=cur->next;
    }
}

LinkList::~LinkList()
{
    Node* cur=head;
    while(cur){
        Node *next=cur->next;
        delete cur;
        cur=next;
    }
}
