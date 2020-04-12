//
//  main.cpp
//  DeletionOfNodeAtPOSinLL
//
//  Created by Gorakh Chavan on 11/04/20.
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
    struct Node * TempPtr,*NewNode;
    head=new Node;
    head->data=a[0];
    head->next=NULL;
    TempPtr=head;
    for(int i=1;i<n;i++)
    {
        NewNode=new Node;
        NewNode->data=a[i];
        NewNode->next=NULL;
        TempPtr->next=NewNode;
        TempPtr=NewNode;
    }

}
void display(struct Node *TempPtr)
{
    while(TempPtr)
    {
        cout<<TempPtr->data<<" ";
        TempPtr=TempPtr->next;
    }
}
void Delete(int position)
{
    struct Node *TailNode=NULL;
    struct Node *TempNode;
    TempNode=head;
    if(position==1)
    {
        head=TempNode->next;
        delete TempNode;
    }
    else{
            for(int i=0;i<position-1&&TempNode;i++)
            {
                TailNode=TempNode;
                TempNode=TempNode->next;
            }
        if(TempNode)
        {
            TailNode->next=TempNode->next;
            delete TempNode;
        }

        }

}
int main()
{
    int a[]={10,20,30,40};
    int length=4;
    create(a,length);
    Delete(5);
    display(head);
    return 0;
}

//Solution of Best time to Buy And Sell Stock
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//    struct node
//    {
//        int pos;
//        int data;
//    };
//    int maxProfit(int p[]) {
//
//       int n=5;
//        int val=0;
//        struct node A[30];
//        int k=0;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=i+1;j<n;j++)
//            {
//                if(p[i]-p[j]>0)
//                {
//                    A[k].pos=i;
//                    A[k].data=p[i]-p[j];
//                    k++;
//                }
//            }
//        }
//         int max=A[0].data;
//        val=max-(A[0].pos+1);
//        for(int i=1;i<=k;i++)
//        {
//
//            if(max<A[i].data)
//            {
//                max=A[i].data;
//                val=(max-(A[i].pos));
//            }
//        }
//
//        return val;
//    }
//};
//int main()
//{
//    int p[]={7,6,4,3,1};
//    Solution s;
//    cout<<s.maxProfit(p);
//}
