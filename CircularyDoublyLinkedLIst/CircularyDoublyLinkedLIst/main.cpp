//
//  main.cpp
//  CircularyDoublyLinkedLIst
//
//  Created by Gorakh Chavan on 20/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//
#include <iostream>
using namespace std;
class Node
{
public:
    Node*prev;
    int data;
    Node*next;
};
class Doubly
{
private:
    Node*head;
public:
    Doubly()
    {
        head=NULL;
    }
    Doubly(int A[],int n);
    ~Doubly();
//    void create();
    int Length();
    void insert(int data,int position);
    int Delete(int index);
    void Display();
    
};

Doubly::Doubly(int A[],int n)
{
    Node* temp,*last,*NewNode;
    temp=new Node;
    temp->data=A[0];
    temp->prev=temp->next=NULL;
    head=temp;
    last=head;
    for(int i=1;i<n;i++)
    {
        NewNode=new Node;
        NewNode->data=A[i];
        NewNode->prev=last;
        NewNode->next=NULL;
        last->next=NewNode;
        last=last->next;
    }
    last->next=head;
    head->prev=last;
    
}
void Doubly::Display()
{
    Node*temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    
}
int Doubly::Length()
{
    Node*temp=head;
    int len=1;
    while(temp->next!=head)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
void Doubly:: insert(int data,int index)
{
    Node*temp=head,*NewNode;
    if(index<0||index>Length())
    {
        cout<<"Cannot be inserted";
        return;
    }
    if(index==0)
    {
        NewNode=new Node;
        NewNode->data=data;
        NewNode->next=temp;
        NewNode->prev=temp->prev;
        temp->prev=NewNode;
        NewNode->prev->next=NewNode;
        head=temp->prev;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            temp=temp->next;
        NewNode=new Node;
        NewNode->data=data;
        NewNode->prev=temp;
        NewNode->next=temp->next;
        if(temp->next)
            NewNode->next->prev=NewNode;
        temp->next=NewNode;
            
    }
}
Doubly::~Doubly()
{
    Node*temp=NULL;
    while(temp)
    {
        temp=head;
        head=head->next;
        delete temp;
        temp=head->next;
        
    }
    
}
int Doubly::Delete(int index)
{
    Node*temp=head;
    int x=0;
    if(index==1)
    {
        head=temp->next;
        x=temp->data;
        temp->prev->next=head;
        temp->next=NULL;
        delete temp;
        if(head)
        {
            head->prev=temp->prev;
        }
    }
    else{
        for(int i=0;i<index-1;i++)
            temp=temp->next;
        temp->prev->next=temp->next;
        if(temp->next)
        {
        temp->next->prev=temp->prev;
        }
        x=temp->data;
        delete temp;
    }
    return x;
}


int main() {
    int A[]={10,20,30,40,50};
    Doubly d(A,5);
//    d.Display();
   d.insert(5, 5);
    d.insert(5, 6);
   d.Delete(1);
     d.Display();
    return 0;
}
