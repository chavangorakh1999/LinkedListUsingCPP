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
int Length(struct Node*p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}
int Delete(struct Node*temp,int pos)
{
    int x=0;
    if(pos<0||pos>Length(head))
    {
        cout<<"Not Deleted";
        return 0;
    }
    if(pos==1)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        x=head->data;
        delete head;
        head=temp->next;
    }
    else{
        for(int i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        struct Node*current;
        current=temp->next;
        temp->next=current->next;
        x=current->data;
        delete current;
        current=temp->next;
    }
    return x;
}
void Insert(struct Node*p,int pos,int val)
{
    struct Node*t;
    
    if(pos<0||pos>Length(head))
    {    cout<<"Not Added"<<endl;
    return;
        
    }
    if(pos==0)
    {
        t=new Node;
        t->data=val;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t=new Node;
        t->data=val;
        t->next=p->next;
        p->next=t;
        
        }
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
    cout<<Delete(head, 5)<<endl;
    Display(head);
    return 0;
}
