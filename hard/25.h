//
// Created by 111 on 2024/9/4.
//

#ifndef ALGORITHM_TEST_25_H
#define ALGORITHM_TEST_25_H

#include "../utils/utils.h"
#include <utility>
#include <tuple>
/* k个一组反转链表 */
// 链表中的节点数目为 n
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
class Solution {
public:
    // 尝试自己写： 我的评价是无疾而终
//    ListNode *reverseKGroup(ListNode *head, int k) {
//        if (k < 2)
//            return head;
//
//        // 按照k值截取并反转链表
//        ListNode *prev = new ListNode(0, head);
//        ListNode *tail = prev -> next;
//
//        ListNode *newHead = new ListNode(0, nullptr);
//
//        for (int i = 0; i < k - 1; i++){
//            tail  = tail ->next;
//        }
//
//        newHead = tail;
//        newHead -> next  = reverseKGroup(head,k-1);
//        return newHead;
//    }

    // 官方题解
    // 翻转一个子链表，并且返回新的头与尾
    std::pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            std::tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};

#endif //ALGORITHM_TEST_25_H
