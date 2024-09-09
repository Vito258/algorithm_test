//
// Created by 860122023 on 2024/8/7.
//
#include "28.h"
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
    std::string s1 = "sadbutsad";
    std::string s2 = "sad";

    std::string s3 = "leetcode";
    std::string s4 = "leeto";

    std::string s5 = "mississippi";
    std::string s6 = "issip";      // 预期结果 4

    std::string s7 = "mississippi";
    std::string s8 = "issi";      // 预期结果 1
    std::cout<<solution.strStr(s7,s8);
}