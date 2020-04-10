//
//  main.cpp
//  ValidPalindrome2
//
//  Created by Gorakh Chavan on 10/04/20.
//  Copyright © 2020 Gorakh Chavan. All rights reserved.
//

#include <iostream>
#include<string.h>
using namespace std;

 class Solution {
 public:
     bool isPalindrome(string s) {
         if(s.size()==0)      return true;
         int i=0,j=(s.size()-1);
         while(i<j){
             if(s[i]!=s[j])
                 break;
             i++;    j--;
         }
         if(i>=j)          return true;
         return false;
     }
     bool validPalindrome(string s) {
         int i=0,j=(s.size()-1);
         while(i<j){
             if(s[i]!=s[j])
                 break;
             i++;   j--;
         }
         if(i>=j)          return true;
         return (isPalindrome(s.substr(i,j-i)) || isPalindrome(s.substr(i+1,j-i)));
     }
 };

//int main() {
//    string s="racer";
//    Solution q;
//    cout<<q.validPalindrome(s);
//    return 0;
//}
