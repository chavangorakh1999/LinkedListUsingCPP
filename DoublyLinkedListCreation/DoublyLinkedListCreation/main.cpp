//
//  main.cpp
//  DoublyLinkedListCreation
//
//  Created by Gorakh Chavan on 16/04/20.
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
    void create();
    int length();
    void Display();
    ~Doubly();
};
int Doubly::length()
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

int main() {
    int A[]={10,20,30,40,50};
    Doubly d(A,5);
    d.Display();
    return 0;
}