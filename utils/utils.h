//
// Created by 860122023 on 2024/9/2.
//

#ifndef ALGORITHM_TEST_UTILS_H
#define ALGORITHM_TEST_UTILS_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode next) : val(x), *next(next) {}
};

#endif //ALGORITHM_TEST_UTILS_H
