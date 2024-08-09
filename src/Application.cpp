//
// Created by 860122023 on 2024/8/7.
//
#include <iostream>
#include "4.h"
int main(){
   std::vector<int> v1{1,15,48,56};
   std::vector<int> v2{5,8,15};
   Solution solution;
   std::cout<< solution.findMedianSortedArrays(v1,v2);
}