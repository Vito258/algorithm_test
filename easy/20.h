//
// Created by 860122023 on 2024/8/27.
//

#ifndef ALGORITHM_TEST_20_H
#define ALGORITHM_TEST_20_H

#include <iostream>
#include <string>
#include <unordered_map>

// 闭合括号
// 1 <= s.length <= 104
// s 仅由括号 '()[]{}' 组成
class Solution {
public:
    // 尝试自己写：
    bool isValid(std::string s) {
        std::unordered_map<char, char> hashmap;

        size_t size = s.size();
        if (size == 1) {
            return false;
        }

        hashmap.insert({'(', ')'});
        hashmap.insert({'{', '}'});
        hashmap.insert({'[', ']'});
        const char *s_ctr = s.c_str();
        // 使用双指针的方法，first 和second一起遍历，开始first 指向第一个字符，second指向第二个字符
        // 当first 为 ( [ { 时暂停对first 的遍历，second向后遍历直到遍历到匹配的) ] } 向后遍历first,将second指向first 的下一个字符...
        int first = 0;
        int second = 1;
        while (first != size) {
            if (hashmap.find(s_ctr[first]) != hashmap.end()) {
                // 找到键值
                while (second != size) {
                    if (hashmap[s_ctr[first]] == s_ctr[second]) {
                        // 找到对应值,开始检测下一个值
                        first++;
                        second = first + 1;
                        break;
                    } else {
                        second++;
                        if (second == size) {
                            return false;
                        }
                    }
                }
            } else {
                first++;
                second++;
            }
        }
        
        return true;
    }

};

#endif //ALGORITHM_TEST_20_H
