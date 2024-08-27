//
// Created by 860122023 on 2024/8/7.
//
#include "20.h"

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
     std::string s1 = "([)]";    // 预期为false
     std::string s2 = "()";      // 预期为true
     std::string s3 = "(){}}{";  // 预期为false
     std::string s4 = "({[)";    // 预期为false
     std::string s5 = "([)]";    // 预期为false
     std::cout<< solution.isValid(s5);
}