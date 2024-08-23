//
// Created by 860122023 on 2024/8/7.
//
#include "19.h"

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
    ListNode l1 = 1;

    ListNode l2 = 2;
    l1.next = &l2;
    ListNode l3 = 3;
    l2.next = &l3;
    ListNode l4 = 4;
    l3.next = &l4;
    ListNode l5 = 5;
    l4.next = &l5;

    // 链表l1
    solution.removeNthFromEnd(&l1,2);
}