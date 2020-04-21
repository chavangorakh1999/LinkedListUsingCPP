//
//  main.cpp
//  FindMiddleElementInLL
//
//  Created by Gorakh Chavan on 21/04/20.
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
    void MiddleElement();
    void DMiddleElement();
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
    
}
void Doubly::Display()
{
    Node*temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
int Doubly::Length()
{
    Node*temp=head;
    int len=0;
    while(temp)
    {
        len++;
        temp=temp->next;
    }
    return len;
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
//using length and traversing in LL
void Doubly:: MiddleElement()
{
    Node*temp=head;
    for(int i=0;i<abs(Length()/2);i++)
    {
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
//using Two pointers
void Doubly:: DMiddleElement()
{
    Node*temp,*tail;
    temp=tail=head;
    while(tail)
    {
        tail=tail->next;
        if(tail)tail=tail->next;
        if(tail)temp=temp->next;
    }
    cout<<temp->data<<endl;
}

int main() {
    int A[]={10,20,30,40,50,60};
    Doubly d(A,6);
    d.DMiddleElement();
     d.Display();
    return 0;
}
