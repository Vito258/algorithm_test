//
// Created by 860122023 on 2024/8/9.
//

#ifndef ALGORITHM_TEST_5_H
#define ALGORITHM_TEST_5_H

#include <string>
#include <unordered_set>

/* 给你一个字符串 s，找到 s 中最长的回文子串 */
class Solution {
public:
    // 第一版：未通过，超出范围错误
    /*存在的问题及改进建议
     * 未能正确处理回文中心
     * 当回文中心为单个字符或两个相同字符时，当前算法只能处理后者。需要额外考虑以每个字符为中心的奇数长度回文和以相邻两个相同字符为中心的偶数长度回文。
     * 边界条件处理不当
     * 在循环结束前，right 指针可能已经越界。
     * 循环条件可能导致遗漏最后一个字符的检查。
     * 未初始化指针
     * resultLeft 和 resultRight 未初始化，可能导致未定义行为。
     * 性能问题
     * 当前算法的时间复杂度较高，可以通过动态规划等方法优化。
     * 代码可读性和可维护性
     * 可以通过增加注释和重构来提高代码的可读性。*/
//    std::string longestPalindrome(std::string s) {
//        const size_t size = s.size();
//        if (size == 0 || size == 1)
//            return s;
//
//        const char *left = s.c_str();
//        const char *right = s.c_str() + 1;
//        int maxLength = 0;
//        const char *resultLeft;
//        const char *resultRight;
//
//        while (left < s.c_str() + size && right < s.c_str() + size) {
//            if (*left != *right) {
//                right++;
//            } else {
//                if ((right - left) > maxLength) {
//                    maxLength = right - left;
//                    resultLeft = left;
//                    resultRight = right;
//                }
//                left++;
//                right = left + 1;
//            }
//        }
//
//        // 计算子字符串的起始位置
//        size_t startPos = resultLeft - &s[0];
//
//        // 计算子字符串的长度
//        size_t length = resultRight - resultLeft + 1;
//
//        // 提取子字符串
//        std::string subStr = s.substr(startPos, length);
//        return subStr;
//    }

    std::string longestPalindrome(std::string s) {
        const size_t size = s.size();
        if (size == 0 || size == 1)
            return s;

        // 初始化结果变量
        int maxLength = 0;
        int resultStart = 0;

        for (int i = 0; i < size; ++i) {
            // 奇数长度回文
            int l = i, r = i;
            while (l >= 0 && r < size && s[l] == s[r]) {
                if ((r - l + 1) > maxLength) {
                    maxLength = r - l + 1;
                    resultStart = l;
                }
                --l;
                ++r;
            }

            // 偶数长度回文
            l = i;
            r = i + 1;
            while (l >= 0 && r < size && s[l] == s[r]) {
                if ((r - l + 1) > maxLength) {
                    maxLength = r - l + 1;
                    resultStart = l;
                }
                --l;
                ++r;
            }
        }

        return s.substr(resultStart, maxLength);
    }
};

#endif //ALGORITHM_TEST_5_H
