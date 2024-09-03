//
// Created by 860122023 on 2024/9/2.
//

#ifndef ALGORITHM_TEST_23_H
#define ALGORITHM_TEST_23_H

#include <vector>
#include <iostream>
#include <queue>
#include "../utils/utils.h"

/* 合并k 个升序链表 */
/*
 * k == lists.length
   0 <= k <= 10^4
   0 <= lists[i].length <= 500
   -10^4 <= lists[i][j] <= 10^4
   lists[i] 按 升序 排列
   lists[i].length 的总和不超过 10^4
*/
class Solution {
public:
    // 自己尝试去写：
    // 类似合并两个升序链表，使用指针的方式同时进行
    // 结果：对链表的操作有问题，应该在dummy 之后定义一个tail 链表去操作，然后定义ans 链表返回结果
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        size_t k = lists.size();
//        ListNode* dummy = new ListNode(0, nullptr);
//        ListNode* tail = dummy;
//        // 外面套一层循环，当list 中所有的链表都为nullptr时，循环结束
//        while(nullptrCount < k){
//            int min = 10001;
//            for (int i = 0; i < k; i++) {
//                if(lists[i] != nullptr)
//                min =  std::min(min,lists[i] -> val);
//            }
//            for(int i=0; i<k; i++){
//                if(lists[i] != nullptr && lists[i] -> val == min){
//                    lists[i]  = lists[i] ->next;
//                tail->next = new ListNode(min, nullptr);
//                tail = tail->next;
//                }
//            }
//            nullptrCount = 0;
//            for(int i = 0; i < k; i++){
//                if(lists[i] == nullptr){
//                    nullptrCount++;
//                }
//            }
//        }
//        ListNode* ans = dummy -> next;
//        delete dummy;
//        return ans;
//    }
//private:
//    int nullptrCount = 0;

//    // 上段代码优化之后的结果，此时它的时间复杂度为O(NK) N 为lists 中所有链表总的节点数，k为list 中链表的size
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        size_t k = lists.size();
//        ListNode* dummy = new ListNode(0, nullptr);
//        ListNode* tail = dummy;
//
//        // 记录空链表的数量
//        int nullptrCount = 0;
//
//        // 初始化空链表数量
//        for (int i = 0; i < k; i++) {
//            if (lists[i] == nullptr) {
//                nullptrCount++;
//            }
//        }
//
//        // 当list 中所有的链表都为nullptr时，循环结束
//        while (nullptrCount < k) {
//
//            // 记录最小值及其索引，这里的索引指的是lists 的索引
//            int minVal = 10001;
//            int minIndex = -1;
//
//            // 查找最小值及其索引
//            for (int i = 0; i < k; i++) {
//                if (lists[i] != nullptr && lists[i]->val < minVal) {
//                    minVal = lists[i]->val;
//                    minIndex = i;
//                }
//            }
//
//            // 更新链表
//            if (minIndex != -1) {
//                tail->next = new ListNode(minVal, nullptr);
//                tail = tail->next;
//                lists[minIndex] = lists[minIndex]->next;
//            }
//
//            // 更新空链表数量
//            if (lists[minIndex] == nullptr) {
//                nullptrCount++;
//            }
//        }
//
//        ListNode* ans = dummy->next;
//        delete dummy;
//        return ans;
//    }


    // 上面两种方式的时间复杂度都为O(Nk),太高了需要优化
    // 官方题解二，分治合并
    // 将 k 个链表配对并将同一对中的链表合并；
    // 第一轮合并以后， k 个链表被合并成了k/2个链表，平均长度为2n/k，然后是k/4个链表，k/8个链表等等；
    // 重复这一过程，直到我们得到了最终的有序链表。
    // 这种方式时间复杂度为O(N logk)

    /* mergeTwoLists 这个方法用于单纯合并两个链表 */
//    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
//        // 当a 或者b 之间有一个是nullptr 时，返回他俩之间不是nullstr 的那个
//        // 如果都是nullptr，返回nullptr
//        if ((!a) || (!b)) return a ? a : b;
//
//        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
//
//        // 当 aptr 和bPtr 都不为nullptr 时
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
//        // 运行到这里说明至少a b 之间至少有一个nullptr ，不是 nullptr 的那个因为本身就是升序链表，
//        // 可以直接接在tail 结果链表的后面
//        tail->next = (aPtr ? aPtr : bPtr);
//        return head.next;
//    }
//
//    ListNode *merge(std::vector<ListNode *> &lists, int l, int r) {
//        // l r 是lists 的左右索引
//        // lists 数组中只有一个元素，这个元素是升序链表可以直接返回
//        if (l == r) return lists[l];
//
//        // 要求的是 合并左右端点，不符合规范，直接排除
//        if (l > r) return nullptr;
//
//        // >> 是右移位运算符，将二进制数向右移动一位相当于除以 2，代替除法操作，以提高效率
//        int mid = (l + r) >> 1;
//
//        // 核心： 使用递归 + 分而治之的方法
//        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
//    }
//
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        return merge(lists, 0, lists.size() - 1);
//    }

    // 官方题解3，使用优先队列合并
    struct Status {
        int val;
        ListNode *ptr;

        // 重写 < 运算符，比较Status 时比较val 值的大小,注意这里是相反的，val 值越大，优先级越低
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    // 优先队列，这里是一个最大堆，每次取值的时候取优先级最高的值
    std::priority_queue <Status> q;

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // 将每个链表的头节点加入到优先队列
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

#endif //ALGORITHM_TEST_23_H
