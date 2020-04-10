//
//  main.cpp
//  CountAndSumOfLinkedList
//
//  Created by Gorakh Chavan on 10/04/20.
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
//Iterative version of counting linkedlist
int Count(struct Node *TempPtr)
{
    int count=0;
    while(TempPtr)
    {
        count++;
        TempPtr=TempPtr->next;
    }
    return count;
}

//Recursive function of counting elements
int Rcount(struct Node *TempPtr)
{
    if(TempPtr)
    {
        return Rcount(TempPtr->next)+1;
    }
    else
    {
        return 0;
    }
}
//Sum using Iterative version
int Add(struct Node *TempPtr)
{
    int sum=0;
    while(TempPtr)
    {
        sum+=TempPtr->DATA;
        TempPtr=TempPtr->next;
    }
    return sum;
}
//Recursive Function for Adding LL elements
int Radd(struct Node *TempPtr)
{
    if(TempPtr)
    {
        return Radd(TempPtr->next)+TempPtr->DATA;
    }
    else{
        return 0;
    }
}
//Iterative Version for searching max
int max(struct Node *TempPtr)
{
    int max=INT32_MIN;
    while(TempPtr)
    {
        if(max<TempPtr->DATA)
            max=TempPtr->DATA;
        TempPtr=TempPtr->next;
    }
    return max;
}
//Recursive function for searching max
int Rmax(struct Node *TempPtr)
{
    int x;
    if(!TempPtr)
    {
        return INT32_MIN;
    }
    else
    {
        x=Rmax(TempPtr->next);
        return x>TempPtr->DATA?x:TempPtr->DATA;
    }
    return 0;
}
int main()
{
    int a[]={1,2,3,4,5};
    create(a,5);
    display(head);
//    cout<<endl<<Rcount(head)<<endl;
//    cout<<Add(head)<<endl;
//    cout<<Radd(head)<<endl;
    cout<<endl<<Rmax(head)<<endl;
    
    return 0;
}
