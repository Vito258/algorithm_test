//
// Created by 111 on 2024/9/4.
//

#ifndef ALGORITHM_TEST_25_H
#define ALGORITHM_TEST_25_H

#include "../utils/utils.h"
/* k个一组反转链表 */
// 链表中的节点数目为 n
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
class Solution {
public:
    // 尝试自己写：
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2)
            return head;

        // 按照k值截取并反转链表
        ListNode *dummy = new ListNode(0, head);
        ListNode *tail = dummy -> next;

        ListNode *newHead = new ListNode(0, nullptr);

        for (int i = 0; i < k - 1; i++){
            tail  = tail ->next;
        }

        newHead = tail;
        newHead -> next  = reverseKGroup(head,k-1);
        return newHead;
    }
};

#endif //ALGORITHM_TEST_25_H
