//
// Created by 860122023 on 2024/8/7.
//

#ifndef ALGORITHM_TEST_2_H
#define ALGORITHM_TEST_2_H
#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 两数相加 */
class Solution {
public:
    /* 未通过 */
//    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//        std::string str1;
//        do{
//            str1.push_back(std::to_string(l1 -> val).c_str()[0]);
//            l1 = l1->next;
//        }while(l1);
//
//        std::string str2;
//        do{
//            str2.push_back(std::to_string(l2 -> val).c_str()[0]);
//            l2 = l2->next;
//        }while(l2);
//
//        int r1 =  std::stoi(str1);
//        int r2 =  std::stoi(str2);
//        int result = r1 + r2;
//        std::string result_string = std::to_string(result);
//
//        ListNode *dummy = new ListNode(0);
//        ListNode *current = dummy;
//        for (int i = result_string.size() - 1; i >= 0; i--) {
//            current->next = new ListNode(result_string[i] - '0');
//            current = current->next;
//        }
//
//        ListNode *result_ListNode = dummy->next;
//        delete dummy;
//        return result_ListNode;
//    }

    // 通过了但是复杂度太高（悲
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        // set pre node
//        ListNode* pre = new ListNode(0);
//        //
//        ListNode* cur = pre;
//        int carry = 0;
//        while(l1 != nullptr || l2 != nullptr){
//            int x = l1 == nullptr ? 0:l1 -> val;
//            int y = l2 == nullptr ? 0:l2 -> val;
//            int sum = x + y + carry;
//
//            carry = sum / 10;
//            sum = sum % 10;
//
//            cur -> next = new ListNode(sum);
//            cur = cur -> next;
//
//            if(l1 != nullptr)
//                l1 = l1->next;
//            if(l2 != nullptr)
//                l2 = l2->next;
//        }
//        if(carry == 1)
//            cur-> next = new ListNode(carry);
//        return pre->next;
//    }

    // 官方题解
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                //如果Head为空，即这是第一次循环
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;

            //更新传进来的 ListNode值，以用于下一位的计算
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

#endif //ALGORITHM_TEST_2_H
