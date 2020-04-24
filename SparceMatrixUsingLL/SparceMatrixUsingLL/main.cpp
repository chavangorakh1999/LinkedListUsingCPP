//
//  main.cpp
//  SparceMatrixUsingLL
//
//  Created by Gorakh Chavan on 23/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
using namespace std;

class Node
{public:
    int col;
    int data;
    Node*next;
    
}*head;
class Sparse
{
private:
     Node*next;
public:
    Sparse()
    {
        next=NULL;
    }
//    Sparse(int m,int n)
//    {
//
//    }
    
    void display(Node *A[],int m,int n)
     
    {
     
    Node *temp;
     
     
    for(int i=0;i<m;i++)
    {
    temp=A[i];
    cout<<i+1<<". ";
    while(temp)
    {
    cout<<temp->col<<","<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
    }
    }
    
};
int main()
{
    int m,n;
    cout<<"Dimension:";
    cin>>m>>n;
    
    Node *A[m],*NewNode,*temp;
    head=temp=A[0];
    for(int i=0;i<m;i++)
    {
        int ele;
        cout<<"Element Count:";
        cin>>ele;
        cout<<endl;
        A[i]=temp=NULL;
        //temp->next=NULL;
        for(int j=0;j<ele;j++)
        {
            
            NewNode=new Node;
            cout<<"col:";
            cin>>NewNode->col;
            cout<<endl;
            cout<<"data:";
            cin>>NewNode->data;
            cout<<endl;
            NewNode->next=NULL;
            if(A[i]==NULL)
            {
                A[i]=temp=NewNode;
            }
            else
            {
                temp->next=NewNode;
                temp=temp->next;
            }
            
        }
        
    }
    Sparse s;
    s.display(A,m,n);
    return 0;
}
