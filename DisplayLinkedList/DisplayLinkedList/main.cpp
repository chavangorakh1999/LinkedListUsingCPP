//
//  main.cpp
//  DisplayLinkedList
//
//  Created by Gorakh Chavan on 09/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node
{
    int DATA;
    struct Node *next;
}*head;
void create(int a[],int n)
{
    int i;
    struct Node *NewNode,*LastPtr=NULL;
    head=new Node;
    head->DATA=a[0];
    head->next=NULL;
    LastPtr=head;
    for(i=1;i<n;i++)
    {
        NewNode=new Node;
        NewNode->DATA=a[i];
        NewNode->next=NULL;
        LastPtr->next=NewNode;
        LastPtr=NewNode;
        
        
    }
}
void display(struct Node *TempPtr)
{
    while(TempPtr!=NULL)
    {
        cout<<TempPtr->DATA<<" ";
        TempPtr=TempPtr->next;
        
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    create(a,5);
    display(head);
    
    return 0;
}
