//
//  main.cpp
//  ConcatAndMergeLL
//
//  Created by Gorakh Chavan on 14/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//
 //

 #include <iostream>
 using namespace std;
 struct Node
 {
     int data;
     struct Node *next;
 }*head=NULL,*second=NULL,*third=NULL;
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
void Merge(struct Node* head1,struct Node* head2)
{
    struct Node* tail;
    if(head1->data<head2->data)
    {
        third=tail=head1;
        head1=head1->next;
        third->next=NULL;
        
        
    }
    else
    {
        third=tail=head2;
        third->next=NULL;
        head2=head2->next;
    }
    while(head1&&head2)
    {
        if(head1->data<head2->data)
        {
            tail->next=head1;
            tail=head1;
            head1=head1->next;
            tail->next=NULL;
        }
        else
        {
            tail->next=head2;
            tail=head2;
            head2=head2->next;
            tail->next=NULL;
        }
    }
    if(head1)tail->next=head1;
    if(head2)tail->next=head2;
}
void loop(struct Node* temp)
{
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head->next->next;
}
int isLoop(struct Node *tempPtr)
{
    struct Node *p,*q;
    p=q=tempPtr;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:NULL;
    }while(p&&q&&p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}
 int main()
 {
    int a[]={2,3,6,8,12};
//     int b[]={4,5,7,9,10};
     create(a,5);
//     screate(b,5);
    
 //    cout<<endl<<Isearch(head, 5)<<endl;
 //     cout<<endl<<Isearch(head, 2)<<endl;
 //    RecReverse(NULL, head);
//      display(head);
//     cout<<endl;
//     display(second);
//     cout<<endl;
//     Merge(head, second);
//     display(third);
//     loop(head);
     cout<<isLoop(head);
     return 0;
 }

