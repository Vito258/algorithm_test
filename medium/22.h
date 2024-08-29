//
// Created by 111 on 2024/8/29.
//

#ifndef ALGORITHM_TEST_22_H
#define ALGORITHM_TEST_22_H

#include <iostream>
#include <string>
#include <vector>

/* 括号生成 */
// 1 <= n <= 8
class Solution {
public:
    // 尝试自己写：
    std::vector<std::string> generateParenthesis(int n) {
        // 先处理特殊情况
        if (n == 1) {
            return {"()"};
        }

        // 字符串内容但从 "("来看，索引0 肯定是"("，末尾肯定是")",而中间各种排列组合的种类数就是result 数组的元素数
        // 字符串长度为2*n
        size_t size = 2 * n;

        // 在[1,2n-2] 之间，寻找(n-1) 个数的排列组合

    }
};

#endif //ALGORITHM_TEST_22_H
