//
// Created by 860122023 on 2024/8/23.
//

#ifndef ALGORITHM_TEST_19_H
#define ALGORITHM_TEST_19_H

#include <iostream>
#include <stack>

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
    // 第一次尝试自己写，竟然一个测试用例也没通过...
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        // 判断链表有几个值
//        int size = 1;
//
//        const ListNode *head_copy = head;
//        while (head_copy-> next != nullptr){
//            size++;
//            head_copy = head_copy->next;
//        }
//
//        // 改为正数 第n 个值
//        n = size - n;
//
//        ListNode *result = head;
//        for(int i=0; i<n ; i++){
//           if(i == n-1){
//               result -> next = result ->next ->next;
//           }
//           result = result -> next;
//        }
//        return result;
//    }

    //传统方法， 遍历两次，第一次计数，第二次删除
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        size_t size = 0;
//        ListNode *current = head;
//        while (current != nullptr) {
//            size++;
//            current = current->next;
//        }
//
//        // 假如是空链表
//        if (size == 0) {
//            return nullptr;
//        }
//
//        // 假如删除的是头节点
//        if (n == size) {
//            return head->next;
//        }
//
//        n = size - n;
//        current = head;
//        for(int i = 0; i< n; i++){
//            if(i == n-1){
//                current ->next = current -> next -> next;
//            }else{
//                current = current ->next;
//            }
//        }
//        return head;
//    }

    // 方法二，使用栈的方式
    // 也可以在遍历链表的同时将所有节点依次入栈。根据栈「先进后出」的原则，我们弹出栈的第 n 个节点就是需要删除的节点，并且目前栈顶的节点就是待删除节点的前驱节点。这样一来，删除操作就变得十分方便了。
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 这里使用哑节点的目的是如果要删除的是头节点的话直接操作head 会比较麻烦，使用哑节点一视同仁，简化操作
        ListNode *dummy = new ListNode(0, head);
        std::stack<ListNode *> stk;
        ListNode *cur = dummy;

        //将链表中所有的值插入到栈中
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }

        // 栈是先进后出，所以是倒着遍历
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }

        ListNode *prev = stk.top();
        prev->next = prev->next->next;

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }

    // 方法三：双指针
    // first 和 second 均指向头节点。我们首先使用 first 对链表进行遍历，遍历的次数为 n。此时，first 和 second 之间间隔了 n−1 个节点，即 first 比 second 超前了 n 个节点。
    // 在这之后，我们同时使用 first 和 second 对链表进行遍历。当 first 遍历到链表的末尾（即 first 为空指针）时，second 恰好指向倒数第 n 个节点。
    // 假设second 首先指向哑节点，那么当first 遍历到nullptr 时，second 指向的节点的下一个节点正好是要删除的节点
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        if (head == nullptr) {  // 处理空链表
//            return nullptr;
//        }
//        ListNode* dummy = new ListNode(0, head);
//        ListNode* first = head;
//        ListNode* second = dummy;
//        for(int i =0;i<n; i++){
//            if (first == nullptr) {
//                delete dummy;  // 如果 n 大于链表长度，释放哑节点
//                return head;   // 返回原始链表
//            }
//            first = first -> next;
//        }
//
//        while(first != nullptr){
//            first = first -> next;
//            second = second -> next;
//        }
//        second -> next = second -> next -> next;
//        ListNode* result = dummy->next;
//        delete dummy;
//        return result;
//    }
};

#endif //ALGORITHM_TEST_19_H
