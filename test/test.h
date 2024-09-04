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
//    struct Status {
//        int val;
//        ListNode *node;
//
//        bool operator<(const Status &rhs) const {
//            return val > rhs.val;
//        }
//    };
//
//    std::priority_queue<Status> p;
//
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        ListNode *head = new ListNode(0, nullptr);
//        ListNode *tail = head;
//
//        for (ListNode *a: lists) {
//            if (a) p.push({a->val, a});
//        }
//
//        while (!p.empty()) {
//            auto f = p.top();
//            p.pop();
//            tail->next = f.node;
//            tail = tail->next;
//            if (f.node -> next)
//                p.push({f.node ->next->val,f.node ->next});
//        }
//        return head->next;
//    }

    // 使用Status 是不是有点丑陋？
    // 1、直接在优先队列里面储存ListNode，并改写ListNode 的 < 运算符  这样做不对，还是需要在ListNode中定义friend 函数才能在外面改动
    // 2、直接给优先队列 自定义比较器
//    struct CompareListNode {
//        bool operator()(const ListNode* lhs, const ListNode* rhs) const {
//            return lhs->val > rhs->val; // 按照从小到大的顺序
//        }
//    };
//
//    // 使用 std::priority_queue，并指定三个模板参数：
//    // 第一个参数是队列中存储的对象类型 ListNode。
//    // 第二个参数是底层容器类型，默认为 std::vector<ListNode>。
//    // 第三个参数是自定义比较器类型 CompareListNode。
//    std::priority_queue<ListNode *, std::vector<ListNode*>, CompareListNode> q;
//
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//      for(auto a: lists){
//          if(a) q.push(a);
//      }
//
//      ListNode *dummy = new ListNode(0, nullptr);
//      ListNode *tail = dummy;
//      while(!q.empty()){
//          ListNode* f = q.top();q.pop();
//          tail->next = f;
//          tail = tail ->next;
//          if(f -> next) q.push(f->next);
//      }
//        return dummy ->next;
//    }

    // 24.两两交换链表中的结点
//     ListNode *swapPairs(ListNode *head) {
//        ListNode *dummy = new ListNode(0, head);
//        ListNode *prev = dummy;
//        ListNode *curr = dummy -> next;
//
//        while(curr && curr ->next){
//            ListNode *next = curr ->next;
//            next -> next = curr;
//            ListNode *nextPair = curr ->next ->next;
//            curr ->next = nextPair;
//
//            prev ->next = next;
//            prev = curr;
//            curr = nextPair;
//        }
//         return dummy ->next;
//     }

    // 使用递归的写法
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *headNext = head->next;

        ListNode *pair = swapPairs(headNext->next);
        headNext->next = head;
        head -> next = pair;
        return headNext;
    }
};

#endif //ALGORITHM_TEST_TEST_H
