//
//  main.cpp
//  RecursiveReverseOfLinkedList
//
//  Created by Gorakh Chavan on 13/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//



#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*head=NULL,*second=NULL,*third;
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
void screate(int b[],int n)
{
    int i;
    struct Node *NewNode,*TailNode;
    second=new Node;
    second->data=b[0];
    second->next=NULL;
    TailNode=second;
    for(i=1;i<n;i++)
    {
        NewNode=new Node;
        NewNode->data=b[i];
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
void concat(struct Node* first,struct Node* second)
{
    struct Node*TempPtr=head;
    while(TempPtr->next!=NULL)
    {TempPtr=TempPtr->next;}
    TempPtr->next=second;
    second=NULL;
}
void RecReverse(struct Node *TailPtr,struct Node *HeadPtr)
{
    if(HeadPtr!=NULL)
    {
        RecReverse(HeadPtr, HeadPtr->next);
        HeadPtr->next=TailPtr;
    }
    else{
        head=TailPtr;
    }
}
void Merge(struct Node *head,struct Node *second)
{
 
}
int main()
{
   int a[]={1,2,3,4,5};
    int b[]={6,7,8,9,10};
    create(a,5);
    screate(b,5);
   
//    cout<<endl<<Isearch(head, 5)<<endl;
//     cout<<endl<<Isearch(head, 2)<<endl;
//    RecReverse(NULL, head);
     display(head);
    cout<<endl;
    display(second);
    cout<<endl;
    concat(head, second);
    display(head);
    
    return 0;
}

