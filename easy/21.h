//
// Created by 111 on 2024/8/28.
//

#ifndef ALGORITHM_TEST_21_H
#define ALGORITHM_TEST_21_H

#include <iostream>
#include <stack>
#include <algorithm>
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

// 合并两个有序链表

// 两个链表的节点数目范围是 [0, 50]
// -100 <= Node.val <= 100
// l1 和 l2 均按 非递减顺序 排列
// 注意这里 l1 l2 按递增顺序排列
class Solution {
public:
    // 第一次尝试自己写，可以使用 双指针的方式
    // 两个指针分别指向两个链表
//    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
//        // 处理特殊情况
//        if(list1 == nullptr && list2 == nullptr){
//            return nullptr;
//        }else if(list1 != nullptr && list2 == nullptr){
//            return list1;
//        }else if(list1 == nullptr){
//            return list2;
//        }
//
//        auto* dummy = new ListNode(INT_MIN, nullptr);
//        ListNode* result = dummy -> next;
//        while (list1 != nullptr || list2 != nullptr) {
//            if(list1 == nullptr){
//                list1 ->val = INT_MAX;
//            }else if(list2 == nullptr){
//                list2 ->val = INT_MAX;
//            }
//
//            if(list1 -> val > list2 -> val){
//                dummy -> next = new ListNode(list1->val, nullptr);
//                list1 = list1 -> next;
//            } else if(list1 -> val < list2 -> val){
//                dummy -> next = new ListNode(list2->val, nullptr);
//                list2 = list2 -> next;
//            } else{
//                dummy -> next = new ListNode(list1->val, nullptr);
//                dummy = dummy -> next;
//                dummy -> next = new ListNode(list2->val, nullptr);
//                list1 = list1 -> next;
//                list2 = list2 -> next;
//            }
//            dummy = dummy ->next;
//        }
//        delete dummy;
//        return result;
//    }

    // 生成优化建议
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        // 处理特殊情况
//        if (list1 == nullptr) return list2;
//        if (list2 == nullptr) return list1;
//
//        ListNode* dummyHead = new ListNode(INT_MIN, nullptr);
//        ListNode* tail = dummyHead;
//
//        while (list1 != nullptr && list2 != nullptr) {
//            if (list1->val < list2->val) {
//                tail->next = list1;
//                list1 = list1->next;
//            } else if (list1->val > list2->val) {
//                tail->next = list2;
//                list2 = list2->next;
//            } else {  // 当两个节点的值相等时，都加入结果链表
//                tail->next = list1;
//                list1 = list1->next;
//                tail = tail->next;
//                tail->next = list2;
//                list2 = list2->next;
//            }
//            tail = tail->next;
//        }
//
//        // 将剩余的链表添加到结果链表的末尾
//        if (list1 != nullptr) {
//            tail->next = list1;
//        } else {
//            tail->next = list2;
//        }
//
//        // 返回合并后的链表
//        ListNode* result = dummyHead->next;
//        delete dummyHead;  // 释放虚拟头结点
//        return result;
//    }

    // 官方题解：使用递归（shit，根本想不到！！！！！
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

#endif //ALGORITHM_TEST_21_H
