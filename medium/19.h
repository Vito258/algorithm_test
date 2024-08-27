//
// Created by 860122023 on 2024/8/23.
//

#ifndef ALGORITHM_TEST_19_H
#define ALGORITHM_TEST_19_H
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 删除链表的倒数第 N 个结点 */
class Solution {
public:
    // 第一版，尝试自己写，为什么自己的测试没问题，力扣的测试用例过不去
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 判断链表有几个值
        int size = 1;

        ListNode *head_copy = head;
        while (head_copy->next != nullptr){
            size++;
            head_copy = head_copy->next;
        }

        // 改为正数 第n 个值
        n = size - n;

        ListNode *result = head;
        for(int i=0; i<n ; i++){
           std::cout<< result->val<<std::endl;
           if(i == n-1){
               result -> next = result ->next ->next;
           }
           result = result -> next;
        }
        return result;
    }
};

#endif //ALGORITHM_TEST_19_H
