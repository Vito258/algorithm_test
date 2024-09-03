//
// Created by 860122023 on 2024/8/7.
//
#include "23.h"
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
    l1->next = new ListNode(4, nullptr);
    l1->next = new ListNode(5, nullptr);

    ListNode *l2 = new ListNode(1, nullptr);
    l2->next = new ListNode(3, nullptr);
    l2->next = new ListNode(4, nullptr);

    ListNode *l3 = new ListNode(2, nullptr);
    l3->next = new ListNode(6, nullptr);

    std::vector<ListNode *> list1;
    list1.push_back(l1);
    list1.push_back(l2);
    list1.push_back(l3);

    auto result =  solution.mergeKLists(list1);
    while(result != nullptr){
        std::cout<<result ->val<< std::endl;
        result = result->next;
    }
}