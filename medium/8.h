//
// Created by 860122023 on 2024/8/12.
//

#ifndef ALGORITHM_TEST_8_H
#define ALGORITHM_TEST_8_H

#include <string>
#include <iostream>
/* 字符串转换整数 */
class Solution {
public:
    // 第一版，理解有误"0-1"时应返回 0，"words and 987"应返回 0
//    int myAtoi(std::string s) {
//        // 去除前导和末尾的空格
//        auto start = s.find_first_not_of(" \t\n\r\f\v"); // 查找第一个非空白字符的位置
//        if (start == std::string::npos)
//            return 0; // 如果全是空白字符，则返回空字符串
//        auto end = s.find_last_not_of(" \t\n\r\f\v"); // 查找最后一个非空白字符的位置
//        s = s.substr(start, (end - start + 1));// 返回修剪后的字符串
//
//        // 第一个数字所在的索引
//        int i = s.find_first_of("123456789");
//        // 查找符号
//        bool is_negative = false;
//        auto plus_sign = s.find_first_of("+");
//        auto dash_sign = s.find_first_of("-");
//        if(dash_sign != std::string::npos && dash_sign < i){
//            is_negative = true;
//        }
//        // 如果两者都不存在，记为正数
//        if (plus_sign == std::string::npos && dash_sign == std::string::npos) {
//            is_negative = false;
//        }
//
//        // 转换，通过跳过前置0来读取该整数，直到遇到非数字字符或者字符串的结尾
//        long result = 0;
//        for (i; i < s.size(); i++) {
//            if(isdigit(s[i])){
//                result =  result * 10 + s[i] - '0';
//            }else{
//                break;
//            }
//        }
//        if(is_negative){
//            result = -result;
//        }
//        result = result >= INT_MAX ? INT_MAX - 1 : result;
//        result = result < INT_MIN ? INT_MIN : result;
//        return static_cast<int>(result);
//    }
};

#endif //ALGORITHM_TEST_8_H
