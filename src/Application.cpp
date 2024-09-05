//
// Created by 860122023 on 2024/8/7.
//
#include "25.h"
#include "../utils/utils.h"

int main() {
    //10的测试用例
//    std::string s1 = "aa";
//    std::string s2 = "a";
//    std::string s3 = "a*";
//    std::string s4 = "ab";
//    std::string s5 = ".*";
//    std::string s6 = "mississippi";
//    std::string s7 = "mis*is*p*.";     //预期结果是false
//    std::string s8 = "mis*is*ip*.";    //预期结果是true
//    Solution solution;
//    std::cout<< solution.isMatch(s6,s7);

    Solution solution;
    ListNode *l1 = new ListNode(1, nullptr);
    l1->next = new ListNode(2, nullptr);
    l1->next ->next = new ListNode(3, nullptr);
    l1->next -> next -> next = new ListNode(4, nullptr);
    l1->next -> next -> next  -> next = new ListNode(5, nullptr);

    solution.reverseKGroup(l1,2);
}