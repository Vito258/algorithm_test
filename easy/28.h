//
// Created by 111 on 2024/9/9.
//

#ifndef ALGORITHM_TEST_28_H
#define ALGORITHM_TEST_28_H

#include <iostream>
#include <string>

/* 找出字符串中第一个匹配项的下标 */
// 1 <= haystack.length, needle.length <= 104
// haystack 和 needle 仅由小写英文字符组成
class Solution {
public:
    // 尝试自己写，使用双指针法
    // 错误： 未通过的测试用例
    // haystack = "mississippi"
    // needle = "issip"
    // 预期结果 4 ，输出 -1；
//    int strStr(std::string haystack, std::string needle) {
//        size_t m = haystack.size();
//        size_t n = needle.size();
//
//        int first = 0;
//        int second = 0;
//        while (first < m && second < n) {
//            if (haystack[first] == needle[second]) {
//                second++;
//            } else {
//                second = 0;
//            }
//            first++;
//        }
//        if (second == n) {
//            return first - n;
//        } else {
//            return -1;
//        }
//    }

    // 超出时间限制，dawn！！！！
    int strStr(std::string haystack, std::string needle) {
        size_t m = haystack.size();
        size_t n = needle.size();

        // 处理空字符串的情况
        if (n == 0) {
            return 0;
        }

        int first = 0;
        int second = 0;
        while (first < m && second < n) {
            if (haystack[first] == needle[second]) {
                second++;
            } else if (second != 0) {
                // 需要将first 回退到一个合适的位置

                first -= (n - second + 1);
                second = 0;

            }
            first++;
        }
        if (second == n) {
            return first - n;
        } else {
            return -1;
        }
    }
};

#endif //ALGORITHM_TEST_28_H
