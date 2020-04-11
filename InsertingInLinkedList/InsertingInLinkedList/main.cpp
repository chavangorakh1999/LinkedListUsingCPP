//
//  main.cpp
//  InsertingInLinkedList
//
//  Created by Gorakh Chavan on 11/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head;
void create(int a[],int n)
{
    int i;
    struct Node *NewNode,*TailNode;
    head=new Node;
    head->data=a[0];
    head->next=NULL;
    TailNode=head;
    for(i=1;i<n;i++)
    {
        NewNode=new Node;
        NewNode->data=a[i];
        NewNode->next=NULL;
        TailNode->next=NewNode;
        TailNode=NewNode;
        
    }
}
void display(struct Node *tempptr)
{
    if(tempptr!=NULL)
    {
        cout<<tempptr->data<<" ";
        display(tempptr->next);
        
        
    }
}
void InsertInLL(int pos,int value)
{
    struct Node *NewNode,*TempPtr;
    if(pos==0)
    {
        NewNode=new Node;
        NewNode->data=value;
        NewNode->next=head;
        head=NewNode;
    }
    else if(pos>0)
    {
        TempPtr=head;
        for(int i=0;i<pos-1&&TempPtr;i++)
        {
            TempPtr=TempPtr->next;
        }
        NewNode=new Node;
        NewNode->data=value;
        NewNode->next=TempPtr->next;
        TempPtr->next=NewNode;
        
    }
}
    
int main()
{
   int a[]={1,2,3,4,5};
    create(a,5);
    InsertInLL(5, 76);
    display(head);
    return 0;
}
