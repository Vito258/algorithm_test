//
// Created by 860122023 on 2024/8/12.
//

#ifndef ALGORITHM_TEST_7_H
#define ALGORITHM_TEST_7_H

#include <string>
#include <iostream>
#include <vector>

/* 整数反转 */
class Solution {

    // 第一次提交，报错：
    //  terminate called after throwing an instance of 'std::out_of_range'
    //  what():  basic_string::erase: __pos (which is 45) > this->size() (which is 3)
//    int reverse(int x) {
//        std::string x_string = std::to_string(x);
//        bool is_negative;
//        if(x_string.find('-')){
//            x_string.erase('-');
//            is_negative = true;
//        }
//
//        const char* x_array = x_string.c_str();
//        int size = x_string.size();
//        std::string s_result;
//        for(int i=0;i<x_string.size();i++){
//            s_result.push_back(x_array[(size - i - 1)]);
//        }
//
//        int i_result =  std::stoi(s_result);
//        if(is_negative){
//            i_result = - i_result;
//        }
//        return i_result;
//    }


public:
    // 使用字符串转换的方法，执行速度较慢，内存消耗偏大
//    int reverse(int x) {
//        std::string x_string = std::to_string(x);
//        bool is_negative = false;
//        if (x_string[0] == '-') {
//            is_negative = true;
//            x_string.erase(0, 1); // Remove the negative sign
//        }
//
//        std::string s_result;
//        int size = x_string.size();
//
//        for (int i = 0; i < x_string.size(); i++) {
//            s_result.push_back(x_string[(size - i - 1)]);
//        }
//        // Check for overflow
//        if (s_result.size() > 10 || (s_result.size() == 10 && (s_result > "2147483647" || s_result < "-2147483648"))) {
//            return 0; // Return 0 in case of overflow
//        }
//
//        int i_result = std::stoi(s_result);
//        if (is_negative) {
//            i_result = -i_result;
//        }
//        return i_result;
//    }

     //避免使用字符串转换，而是使用直接操作整数的方法
     int reverse(int x) {
         //使用long 类型声明结果对象，防止转换时溢出异常
         long reversedInt = 0;
         while (x != 0) {
             int pop = x % 10;
             x /= 10;

             // 查看是否溢出，如果是，立马返回 0
             if (reversedInt > INT_MAX / 10 || (reversedInt == INT_MAX / 10 && pop > 7)) return 0;
             if (reversedInt < INT_MIN / 10 || (reversedInt == INT_MIN / 10 && pop < -8)) return 0;

             reversedInt = reversedInt * 10 + pop;
         }
         return static_cast<int>(reversedInt);
     }
};

#endif //ALGORITHM_TEST_7_H
