//
//  main.cpp
//  SinglyCircularLinkedList
//
//  Created by Gorakh Chavan on 15/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node * next;
}*head;
void create(int a[],int n)
{
    struct Node*temp,*NewNode;
    temp=new Node;
    temp->data=a[0];
    temp->next=NULL;
    head=temp;
    for(int i=1;i<n;i++)
    {
        
        NewNode=new Node;
        NewNode->data=a[i];
        NewNode->next=NULL;
        temp->next=NewNode;
         temp=temp->next;
       
    }
    temp->next=head;
}
//iterative version
void display(struct Node*p)
{
//    static int flag=0;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
//recursive Display version
void Display(struct Node *p)
{
    static int flag=0;
    if(p!=head||flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        Display(p->next);
    }
    flag=0;
}
int main() {
    int a[]={1,2,3,4,5};
    create(a,5);
    Display(head);
    return 0;
}
