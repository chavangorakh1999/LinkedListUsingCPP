//
//  main.cpp
//  SearchingInLinkedList
//
//  Created by Gorakh Chavan on 10/04/20.
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
//Iterative Version Of searching Key Element
Node* Search(struct Node *TempPtr,int key)
{
    while(TempPtr)
    {
        if(key==TempPtr->data)
            return TempPtr;
        TempPtr=TempPtr->next;
    }
    return NULL;
}
//Recursive Version Of Searching Key Element
Node* Rsearch(struct Node *TempPtr,int key)
{
    if(!TempPtr)
        return NULL;
    if(key==TempPtr->data)
        return TempPtr;
    return Rsearch(TempPtr->next, key);
}
//Improving The Linear Search
Node * Isearch(struct Node *TempPtr,int key)
{
    struct Node *TailPtr=NULL;
    while(TempPtr)
    {
        if(key==TempPtr->data)
        {
            TailPtr->next=TempPtr->next;
            TempPtr->next=head;
            head=TempPtr;
            return TempPtr;
        }
        TailPtr=TempPtr;
        TempPtr=TempPtr->next;
    }
    return NULL;
}
int main()
{
   int a[]={1,2,3,4,5};
    create(a,5);
   
    cout<<endl<<Isearch(head, 5)<<endl;
     cout<<endl<<Isearch(head, 2)<<endl;
     display(head);
    return 0;
}
