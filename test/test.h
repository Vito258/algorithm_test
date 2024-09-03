//
// Created by 860122023 on 2024/9/3.
//

#ifndef ALGORITHM_TEST_TEST_H
#define ALGORITHM_TEST_TEST_H

#include "../hard/23.h"

class Test {
    // 23. 分而治之
    // 合并两个链表的方法
//    ListNode *mergeTwoListNode(ListNode *a, ListNode *b) {
//        if (a == nullptr || b == nullptr)
//            return a ? a : b;
//        ListNode *head = new ListNode(0, nullptr);
//        ListNode *tail = head;
//        ListNode *aPtr = a;
//        ListNode *bPtr = b;
//        while (aPtr && bPtr) {
//            if (aPtr->val < bPtr->val) {
//                tail->next = aPtr;
//                aPtr = aPtr->next;
//            } else {
//                tail->next = bPtr;
//                bPtr = bPtr->next;
//            }
//            tail = tail->next;
//        }
//
//        tail->next = (aPtr ? aPtr : bPtr);
//        return head->next;
//    }
//
//    ListNode *merge(std::vector<ListNode *> lists, int l, int r) {
//        if (l == r) {
//            return lists[r];
//        } else if (l > r) {
//            return nullptr;
//        }
//
//        int mid = (r + l) >> 1;
//
//        return mergeTwoListNode(merge(lists, l, mid), merge(lists, mid + 1, r));
//    }
//
//
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        return merge(lists, 0, lists.size() - 1);
//    }


    //23. 使用优先队列
    struct Status {
        int val;
        ListNode *node;

        bool operator<(const Status &rhs) const {
            return val > rhs.val;
        }
    };

    std::priority_queue<Status> p;

    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        ListNode *head = new ListNode(0, nullptr);
        ListNode *tail = head;

        for (ListNode *a: lists) {
            if (a) p.push({a->val, a});
        }

        while (!p.empty()) {
            auto f = p.top();
            p.pop();
            tail->next = f.node;
            tail = tail->next;
            if (f.node -> next)
                p.push({f.node ->next->val,f.node ->next});
        }
        return head->next;
    }

};

#endif //ALGORITHM_TEST_TEST_H
