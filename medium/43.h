//
// Created by 860122023 on 2024/10/8.
//

#ifndef ALGORITHM_TEST_43_H
#define ALGORITHM_TEST_43_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// 字符串相乘
// 注意： 不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
class Solution {
public:
    // 根据列竖式交叉相乘的方法
    // 报错，越界错误
//    std::string multiply(std::string num1, std::string num2) {
//        int result = 0;
//        for (int i = 0; i < num2.size(); i++) {
//            int num2_last = num2[num2.size() -i - 1] - '0';
//            int temp = 0;
//            for (int j = 0; j < num1.size(); j++) {
//                int num1_last = num1[num1.size() - j - 1] - '0';
//                int combine = num1_last * num2_last * pow(10, j) * pow(10, i);
//                temp += combine;
//            }
//            result += temp;
//        }
//        return std::to_string(result);
//    }

    // 进行优化：
    // 优化方向
    // 类型转换与溢出：确保类型转换正确，并避免整数溢出。
    // 越界错误：修正索引计算，防止数组越界。
    // 性能优化：减少 pow 函数的调用次数。
    // 整数溢出：使用更安全的数据类型来避免整数溢出。
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n1 = num1.size();
        int n2 = num2.size();
        std::vector<int> result(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            // 进位
            int carry = 0;
            int n1_last = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; j--) {
                int n2_last = num2[j] - '0';
                int sum = n1_last * n2_last + result[i + j + 1] + carry;
                result[i + j + 1] = sum % 10;
                carry = sum / 10;
            }
            // 最后一次计算的进位 赋值
            result[i] += carry;
        }

        // 因为是使用Vector 储存值，所以将其转换为字符串
        std::string res_str;
        bool leading_zero = true;
        for (int digit : result) {
            // 仅跳过开头的0
            if (leading_zero && digit == 0) continue;
            leading_zero = false;
            res_str.push_back(digit + '0');
        }
        if (res_str.empty()) {
            return "0";
        }
        return res_str;
    }
};

#endif //ALGORITHM_TEST_43_H
