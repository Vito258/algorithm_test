//
// Created by 860122023 on 2024/9/18.
//

#ifndef ALGORITHM_TEST_29_H
#define ALGORITHM_TEST_29_H

#include <iostream>
#include <cstdlib>
/*  29、两数相除  */
//  -2^31 <= dividend, divisor <= 2^31 - 1
//  divisor != 0
class Solution {
public:

    // 尝试自己写（回归原始，使用纯减法
    // 报错：signed integer overflow，
    int divide(int dividend, int divisor) {
        bool isNegative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);

        int dividend_abs = std::abs(dividend);
        int divisor_abs = std::abs(divisor);

        int result = -1;
        // 排除特殊情况
        // 1、被除数 绝对值小于除数
        // 2、被除数 为0
        if (dividend_abs <  divisor_abs || dividend == 0) {
            return 0;
        }

        // 循环计算
        while(dividend_abs >= 0){
            result++;
            dividend_abs -= divisor_abs;
        }
        if(isNegative){
            result = -result;
        }
        return result;
    }
};

#endif //ALGORITHM_TEST_29_H
