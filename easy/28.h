//
// Created by 111 on 2024/9/9.
//

#ifndef ALGORITHM_TEST_28_H
#define ALGORITHM_TEST_28_H

#include <iostream>
#include <string>
#include <vector>

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
//    int strStr(std::string haystack, std::string needle) {
//        size_t m = haystack.size();
//        size_t n = needle.size();
//
//        // 处理空字符串的情况
//        if (n == 0) {
//            return 0;
//        }
//
//        int first = 0;
//        int second = 0;
//        while (first < m && second < n) {
//            if (haystack[first] == needle[second]) {
//                second++;
//            } else if (second != 0) {
//                // 需要将first 回退到一个合适的位置
//
//                first -= (n - second + 1);
//                second = 0;
//
//            }
//            first++;
//        }
//        if (second == n) {
//            return first - n;
//        } else {
//            return -1;
//        }
//    }

    // 朴素解法
//    int strStr(std::string s, std::string p) {
//        // 这里不能用size_t，size_t 是无符号整数 因为可能会出现 n < m 的情况，此时n - m 为负数
//        int n = s.size(), m = p.size();
//        // 为什么 i <= n - m,因为 i> n-m时，s 中剩余用于比较的字符串已经不足与匹配p ，继续下去毫无意义
//        for(int i = 0; i <= n - m; i++){
//            int j = i, k = 0;
//
//            // 用于实际比较一整段字符串
//            while(k < m and j < n and s[j] == p[k]){
//                j++;
//                k++;
//            }
//
//            // 比较完之后，如果k == m 说明完全匹配，返回s 中的开头索引i，i用于记录，j 用于遍历s
//            if(k == m) return i;
//        }
//        return -1;
//    }

    // 使用KMP 算法实现字符串匹配
    //  KMP算法 KMP算法通过构建部分匹配表（next数组）来避免重复比较，从而提高效率。具体步骤如下：
    //  构建next数组：记录前缀与后缀的最大相同子串长度。
    //  字符串匹配：利用next数组快速跳过不必要的比较。
    int strStr(std::string haystack, std::string needle) {
        size_t m = haystack.size();
        size_t n = needle.size();

        // 空字符串处理
        if (n == 0) {
            return 0;
        }

        if (m < n) {
            return -1;  // haystack长度小于needle长度，直接返回-1
        }

        // 构建KMP表
        // 构建一个有n 个元素的int 数组，初始化每个元素的值为n
        std::vector<int> next(n, 0);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }

        // 字符串匹配
        j = 0;
        for (int i = 0; i < m; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == n) {
                return i - n + 1;
            }
        }

        return -1;
    }
};

#endif //ALGORITHM_TEST_28_H
