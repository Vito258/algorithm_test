//
// Created by 860122023 on 2024/8/13.
//

#ifndef ALGORITHM_TEST_9_H
#define ALGORITHM_TEST_9_H

#include <iostream>
/* 判断是否是回文整数 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int x_init = x;
        long x_convert;
        int pop;
        while(x_init != 0){
            pop = x_init % 10;
            x_init /= 10;
            x_convert = x_convert * 10 + pop;
        }
        // 检查溢出
        if (x_convert >= INT_MAX || x_convert <= INT_MIN) {
            return false;
        }
        return x == x_convert;
    }
};
#endif //ALGORITHM_TEST_9_H
