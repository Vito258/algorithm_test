//
// Created by 860122023 on 2024/8/14.
//

#ifndef ALGORITHM_TEST_10_H
#define ALGORITHM_TEST_10_H

//TODO
#include <iostream>
#include <string>
#include <vector>
/* 正则表达式匹配
 *  . 匹配单个字符
 *  * 匹配多个字符
 * */

class Solution {
public:
    // 未通过测试用例：
    //s = "mississippi"
    //p = "mis*is*p*."
//    bool isMatch(std::string s, std::string p) {
//        size_t s_size = s.size();
//        size_t p_size = p.size();
//
//        size_t flag = p.find_first_of(".*");
//        // 排除没有匹配符的情况
//        if (flag == std::string::npos) {
//            return s == p;
//        }
//
//        size_t size = std::min(s_size, p_size);
//
//        bool result = true;
//        int j = 0;
//        for (int i = 0; i < size; i++) {
//            if (p[i] == '.') {
//                j++;
//                continue;
//            } else if (p[i] == '*') {
//                // 从i开始的下一个都匹配
//                j = s.find_first_of(p[i+1],j);
//                continue;
//            } else {
//               result = (p[i] == s[j]);
//               j++;
//            }
//        }
//        return result;
//    }

    // 官方题解
    /*
     * 使用动态规划算法
     * */
    bool isMatch(std::string s, std::string p) {
        int s_size = s.size();
        int p_size = p.size();

        // 使用lambda 表达式 定义辅助函数matches
        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        // 定义一个二维数组,比较索引位置 i-1,j-1, 所以预设数组大小为size+1，索引 0处设置匹配为 true
        // 二维数组 f 存储子问题的解, f[i][j] 表示 s 的前 i 个字符与 p 的前 j 个字符是否匹配。
        std::vector<std::vector<int>> f(s_size + 1, std::vector<int>(p_size + 1));
        f[0][0] = true;
        for (int i = 0; i <= s_size; ++i) {
            for (int j = 1; j <= p_size; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[s_size][p_size];
    }
};

#endif //ALGORITHM_TEST_10_H
