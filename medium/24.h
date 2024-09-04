//
// Created by 111 on 2024/9/3.
//

#ifndef ALGORITHM_TEST_24_H
#define ALGORITHM_TEST_24_H

#include <iostream>
#include "../utils/utils.h"

/* 两两交换链表中的节点 */
// 只能进行节点交换,不能改变链表中节点的值
// 链表中节点的数目在范围 [0, 100] 内
// 0 <= Node.val <= 100
class Solution {
public:

    // 尝试自己写
    // 出现错误：
    // 空指针检查不足：在 while 循环中，只检查了 tail1->next 是否为空，但没有检查 tail1->next->next 是否为空。如果当前节点是最后一个节点，则会导致访问空指针。
    // 内存泄漏：每次交换节点时创建了两个新的 ListNode 对象，但没有释放旧节点的内存，导致内存泄漏。
//    ListNode *swapPairs(ListNode *head) {
//        ListNode *dummy = new ListNode(0,head);
//
//        ListNode *tail = dummy ->next;
//        ListNode *tail1 = dummy ->next;
//
//        while (tail1->next) {
//            // 交换节点
//            ListNode *temp1 = new ListNode(tail->next->val, tail->next->next);
//            ListNode *temp2 = new ListNode(tail->val, tail->next);
//            tail = temp1;
//            tail->next = temp2;
//
//            //交换下一对
//            tail  = tail -> next ->next;
//        }
//
//        return dummy -> next;
//    }

    // 将上面的代码进行优化
    // 哭இ௰இ，才发现自己一点儿也不懂链表
    // 当head 为(0,1,2,3,4)时的每一步运行结果：
    // 初始状态
    //head 为 (1, 2, 3, 4)。
    //dummy 为 (0, 1, 2, 3, 4)。
    //prev 为 dummy，即 (0)。
    //curr 为 head，即 (1)。

    // 第一次循环
    //curr 为 (1)，curr->next 为 (2)，均不为空，进入循环。
    //保存 nextPair 为 (3)。
    //交换节点：
    //next 为 (2)。
    //next->next 指向 (1)，即 (2)->next = (1)。
    //curr->next 指向 (3)，即 (1)->next = (3)。
    //更新 prev 和 curr：
    //prev->next 指向 (2)，即 (0)->next = (2)。
    //prev 指向 (1)。
    //curr 指向 (3)。

    // 第二次循环
    //curr 为 (3)，curr->next 为 (4)，均不为空，进入循环。
    //保存 nextPair 为 nullptr。
    //交换节点：
    //next 为 (4)。
    //next->next 指向 (3)，即 (4)->next = (3)。
    //curr->next 指向 nullptr，即 (3)->next = nullptr。
    //更新 prev 和 curr：
    //prev->next 指向 (4)，即 (1)->next = (4)。
    //prev 指向 (3)。
    //curr 指向 nullptr。

    //结果
    //最终链表结构为 (0, 2, 1, 4, 3)。
    //返回 dummy->next，即 (2)。
//    ListNode *swapPairs(ListNode *head) {
//        ListNode *dummy = new ListNode(0, head);
//        ListNode *prev = dummy;
//        ListNode *curr = head;
//
//        while (curr != nullptr && curr->next != nullptr) {
//            // 保存下一个节点
//            ListNode *nextPair = curr->next->next;
//            // 交换节点
//            ListNode *next = curr->next;
//            next->next = curr;
//            curr->next = nextPair;
//            // 更新 prev 和 curr
//            prev->next = next;
//            prev = curr;
//            curr = nextPair;
//        }
//
//        return dummy->next;
//    }

    // 以上方法类似于官方题解2 中的迭代
    // 下面是官方题解1 使用递归
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

#endif //ALGORITHM_TEST_24_H
