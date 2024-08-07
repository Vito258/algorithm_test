//
// Created by 860122023 on 2024/8/7.
//
#include <iostream>
#include "2.h"
int main(){
   ListNode l1;
   ListNode l2(1,&l1);
   ListNode l3 (2,&l2);
   // 此时的l3：{0，1，2}  210

   ListNode n1(3);
   ListNode n2(4,&n1);
   ListNode n3(5,&n2);
   // 此时的n3 :{3, 4, 5} 543

   Solution solution;
   ListNode* result =  solution.addTwoNumbers(&l3,&n3);
    if (result != nullptr) {
        std::cout << result->val << std::endl;
    } else {
        std::cerr << "Error: result is nullptr" << std::endl;
    }
}