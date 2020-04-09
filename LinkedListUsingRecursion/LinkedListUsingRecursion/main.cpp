//
//  main.cpp
//  LinkedListUsingRecursion
//
//  Created by Gorakh Chavan on 09/04/20.
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
        display(tempptr->next);
        cout<<tempptr->data<<" ";
        
    }
}

int main()
{
   int a[]={1,2,3,4,5};
    create(a,5);
    display(head);
    return 0;
}
