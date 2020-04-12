//
//  main.cpp
//  CheckIfLinkedListIsSorted
//
//  Created by Gorakh Chavan on 12/04/20.
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
bool CheckSorrted(struct Node *TempPtr)
{
    int x=INT_MIN;
    while(TempPtr!=NULL)
    {
        if(TempPtr->data<x)
        {
            return false;
        }
        x=TempPtr->data;
        TempPtr=TempPtr->next;
    }
    return true;
}
void RemoveDuplicate(struct Node *TempPtr)
{
    struct Node * TailPtr;
    TailPtr=TempPtr->next;
    while(TailPtr!=NULL)
    {
        if(TempPtr->data==TailPtr->data)
        {
            TempPtr->next=TailPtr->next;
            delete TailPtr;
            TailPtr=TempPtr->next;
        }
        TempPtr=TailPtr;
        TailPtr=TailPtr->next;
    }
}
void ReverseElement(struct Node *TempPtr,int size)
{
    int A[size];
    int i=0;
    while(TempPtr!=NULL)
    {
        A[i]=TempPtr->data;
        i++;
        TempPtr=TempPtr->next;
    }
    int j=i-1;
    TempPtr=head;
    while(TempPtr!=NULL)
    {
        TempPtr->data=A[j];
        j--;
        TempPtr=TempPtr->next;
    }
}
void ReverseLinks(struct Node *HeadPtr)
{
    struct Node *MidPtr,*TailPtr;
    MidPtr=TailPtr=NULL;
    while(HeadPtr!=NULL)
    {
        TailPtr=MidPtr;
        MidPtr=HeadPtr;
        HeadPtr=HeadPtr->next;
        MidPtr->next=TailPtr;
    }
    head=MidPtr;
}
int main()
{
   int a[]={2,2,4,4,5};
    create(a,5);
    ReverseLinks(head);
     display(head);
    return 0;
}
