//
// Created by 860122023 on 2024/9/29.
//
#ifndef ALGORITHM_TEST_38_H
#define ALGORITHM_TEST_38_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 外观数列

// 输入int 值返回 行程长度编码，countAndSay(n) 是countAndSay(n - 1) 的行程长度编码
// 使用迭代的方式
class Solution {
public:
//    std::string countAndSay(int n) {
//        if(n != 1){
//            return getRleString(countAndSay(n-1));
//        }else{
//            return "1";
//        }
//    }

    // 根据字符串返回行程长度编码的方法
    std::string getRleString(std::string string) {
        std::string result;
        int count = 0;
        int temp = 0;

        // 遍历字符串
        int size = string.size();

        // 处理特殊情况
        if(size == 1){
            return "1" + string;
        }
        for (int i = 0; i < size; i++) {
            int val = string[i] - '0';
            if (i == 0) {
                count = 1;
                temp = val;
                continue;
            }
            if (temp == val) {
                count++;
                if (i == size - 1) {
                    std::string tempCount = std::to_string(count) + std::to_string(temp);
                    result.append(tempCount);
                }
                continue;
            }

            if (i != 0 && temp != val) {
                // 处理前面的字符串
                std::string tempCount = std::to_string(count) + std::to_string(temp);
                result.append(tempCount);

                // 重制 参数
                count = 1;
                temp = val;
            }
            if (i == size - 1) {
                std::string tempCount = std::to_string(count) + std::to_string(temp);
                result.append(tempCount);
            }
        }
        return result;
    }

    // 官方题解1，由于官方题解2竟然是打表...  就不看了哈哈
    std::string countAndSay(int n) {
        std::string prev = "1";
           // 进行n-1 次求值
        for (int i = 2; i <= n; ++i) {
            std::string curr = "";
            int start = 0;
            int pos = 0;

            // rle 算法的核心
            while (pos < prev.size()) {
                // 这里又加了一遍pos < prev.size()是为了给prev[pos]加一个前提条件，防止出现越界
                while (pos < prev.size() && prev[pos] == prev[start]) {
                    pos++;
                }
                // pos - start 就是有几个相同的数字，prev[start]就是数字的值
                curr += std::to_string(pos - start) + prev[start];
                start = pos;
            }
            // 得出当前的rle 算法的值
            prev = curr;
        }

        return prev;
    }
};

#endif //ALGORITHM_TEST_38_H
