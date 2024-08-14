//
// Created by 860122023 on 2024/8/7.
//
#include <iostream>
#include "10.h"
int main(){
    std::string s1 = "aa";
    std::string s2 = "a";
    std::string s3 = "a*";
    std::string s4 = "ab";
    std::string s5 = ".*";
    std::string s6 = "mississippi";
    std::string s7 = "mis*is*p*.";     //预期结果是false
    std::string s8 = "mis*is*ip*.";    //预期结果是true
    Solution solution;
    std::cout<< solution.isMatch(s6,s7);
}