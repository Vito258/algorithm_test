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
    std::pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail) {
        // 保存尾节点之后的节点
        ListNode *prev = tail->next;
        ListNode *p = head;

        // 反转从 head 到 tail 之间的链表
        while (prev != tail) {
            // 记录当前节点的下一个节点
            ListNode *nex = p->next;
            // 当前节点指向前一个节点
            // 第一次执行时prev 是tail 的下一个节点，因为将来head是要作为尾节点抛出
            // 所以使head 的next 指向尾节点的下一个节点
            p->next = prev;

            // 更新前一个节点为当前节点
            prev = p;
            // 移动到下一个节点
            p = nex;
        }
        // 返回新的头尾节点对
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        // 创建虚拟头节点
        ListNode *hair = new ListNode(0);
        hair->next = head;
        // 初始化前驱节点
        ListNode *pre = hair;

        while (head) {
            // 初始化当前组尾节点
            ListNode *tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;     // 不足 k 个节点则退出
                }
            }
            // 经过上个for循环现在tail 应该指向链表的第k个值，即子链表的尾节点

            // 保存下一组的第一个节点
            ListNode *nex = tail->next;
            // 这里是 C++17 的结构化绑定，返回一个新的头节点和新的尾节点。这里使用 std::tie 来解构返回的 std::pair 对象，将其中的两个值分别赋给 head 和 tail。
            std::tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            // 前驱节点指向子链表新头节点
            pre->next = head;

            // 子链表新尾节点指向下一组的第一个节点
            tail->next = nex;
            // 更新前驱节点为子链表的新尾节点
            pre = tail;
            // 更新当前处理的头节点为下一组的第一个节点
            head = tail->next;
        }

        // 返回反转后的链表头节点
        return hair->next;
    }
};

#endif //ALGORITHM_TEST_25_H
