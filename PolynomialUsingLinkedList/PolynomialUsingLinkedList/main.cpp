//
//  main.cpp
//  PolynomialUsingLinkedList
//
//  Created by Gorakh Chavan on 23/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    Node*next;
}*poly=NULL;
void  create()
{
    struct Node*temp,*last=NULL;
    int num;
    cout<<"Enter Number of element:";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        temp=new Node;
        cin>>temp->coeff>>temp->exp;
        temp->next=NULL;
        if(poly==NULL)
        {
            poly=last=temp;
        }
        else
        {
            last->next=temp;
            last=temp;
        }
        
    }
}
long eval(int x)
{
    struct Node*temp=poly;
    int val=0;
    while(temp)
    {
        val+=(temp->coeff*pow(x,temp->exp));
        temp=temp->next;
    }
    return val;
}
void Display()
{
    struct Node*temp=poly;
    while(temp)
    {
        cout<<"("<<temp->coeff<<","<<temp->exp<<")"<<endl;
        temp=temp->next;
    }
}

int main()
{
    create();
    Display();
    cout<<eval(1);
    return 0;
}
