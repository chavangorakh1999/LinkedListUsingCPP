//
//  main.cpp
//  InsertInSortedLL
//
//  Created by Gorakh Chavan on 11/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
}*head=NULL;

void create(int a[],int n)
{
    struct Node *NewNode,*TailNode;
    head=new Node;
    head->data=a[0];
    head->next=NULL;
    TailNode=head;
    for(int i=1;i<n;i++)
    {
        NewNode=new Node;
        NewNode->data=a[i];
        NewNode->next=NULL;
        TailNode->next=NewNode;
        TailNode=NewNode;
    }
    
}
void Display(struct Node *TempPtr)
{
    while(TempPtr)
    {
        cout<<TempPtr->data<<" ";
        TempPtr=TempPtr->next;
        
    }
}
void InsertInSorted(struct Node *TempPtr,int value)
{
    struct Node *TailPtr,*NewNode;
    TailPtr=new Node;
    if(head==NULL)
    {
        NewNode=new Node;
        NewNode->data=value;
        NewNode->next=NULL;
        head=NewNode;
    }
    else if(TempPtr->data>value)
    {
        NewNode=new Node;
        NewNode->data=value;
        NewNode->next=TempPtr;
        head=NewNode;
    }
    else{
    while(TempPtr&&TempPtr->data<value)
    {
        TailPtr=TempPtr;
        TempPtr=TempPtr->next;
    }
    NewNode=new Node;
    NewNode->data=value;
    NewNode->next=TailPtr->next;
    TailPtr->next=NewNode;
    
    }}

int main()
{
//    int a[]={};
//    int length=0;
//    create(a,length);
    
    InsertInSorted(head, 35);
    InsertInSorted(head, 30);
    InsertInSorted(head, 100);
    
    Display(head);
    
    
    return 0;
}
