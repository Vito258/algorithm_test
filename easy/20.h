//
// Created by 860122023 on 2024/8/27.
//

#ifndef ALGORITHM_TEST_20_H
#define ALGORITHM_TEST_20_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

// 闭合括号
// 1 <= s.length <= 104
// s 仅由括号 '()[]{}' 组成
class Solution {
public:
    // 尝试自己写：
    // 未通过的测试用例：
    // s =
    //"([)]"
    //预期结果
    //false
//    bool isValid(std::string s) {
//        std::unordered_map<char, char> hashmap;
//
//        size_t size = s.size();
//        if (size == 1) {
//            return false;
//        }
//
//        hashmap.insert({'(', ')'});
//        hashmap.insert({'{', '}'});
//        hashmap.insert({'[', ']'});
//        const char *s_ctr = s.c_str();
//        // 使用双指针的方法，first 和second一起遍历，开始first 指向第一个字符，second指向第二个字符
//        // 当first 为 ( [ { 时暂停对first 的遍历，second向后遍历直到遍历到匹配的) ] } 向后遍历first,将second指向first 的下一个字符...
//        int first = 0;
//        int second = 1;
//        while (first != size) {
//            if (hashmap.find(s_ctr[first]) != hashmap.end()) {
//                // 找到键值
//                while (second != size) {
//                    if (hashmap[s_ctr[first]] == s_ctr[second]) {
//                        // 找到对应值,开始检测下一个值
//                        first++;
//                        second = first + 1;
//                        break;
//                    } else {
//                        second++;
//                        if (second == size) {
//                            return false;
//                        }
//                    }
//                }
//            } else {
//                first++;
//                second++;
//            }
//        }
//
//        return true;
//    }


    // 第二次自己尝试，又没通过。。
    //输入
    //s =
    //"(){}}{"
    //输出
    //true
    //预期结果
    //false
//    bool isValid(std::string s) {
//        std::unordered_map<char, char> hashmap;
//
//        size_t size = s.size();
//        if (size == 1) {
//            return false;
//        }
//
//        hashmap.insert({'(', ')'});
//        hashmap.insert({'{', '}'});
//        hashmap.insert({'[', ']'});
//        const char *s_ctr = s.c_str();
//        // 使用双指针的方法，first 和second一起遍历，开始first 指向第一个字符，second指向第二个字符
//        // 当first 为 ( [ { 时暂停对first 的遍历，second向后遍历直到遍历到匹配的) ] } 向后遍历first,将second指向first 的下一个字符...
//        int first = 0;
//        int second = 1;
//        // 找到键值
//        while (second <= size -1) {
//            if (hashmap.find(s_ctr[first]) != hashmap.end() && hashmap[s_ctr[first]] == s_ctr[second]) {
//                // 找到对应值,开始检测下一个值
//                first = second + 1;
//                second = first + 1;
//                if (first < size && second >= size) {
//                    return false;
//                }
//                break;
//            } else {
//                second++;
//                if (second >= size) {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }

    // 第三次未通过的测试用例：（麻了
    // 输入
    //s =
    //"({[)"
    //输出
    //true
    //预期结果
    //false
//    bool isValid(std::string s) {
//        std::unordered_map<char, char> hashmap;
//
//        size_t size = s.size();
//        if (size == 1) {
//            return false;
//        }
//
//        hashmap.insert({'(', ')'});
//        hashmap.insert({'{', '}'});
//        hashmap.insert({'[', ']'});
//        const char *s_ctr = s.c_str();
//        // 使用双指针的方法，first 和second一起遍历，开始first 指向第一个字符，second指向第二个字符
//        // 当first 为 ( [ { 时暂停对first 的遍历，second向后遍历直到遍历到匹配的) ] } 向后遍历first,将second指向first 的下一个字符...
//        int first = 0;
//        int second = 1;
//        // 找到键值
//        while (second <= size -1) {
//            if (hashmap.find(s_ctr[first]) != hashmap.end() && hashmap[s_ctr[first]] == s_ctr[second]) {
//                // 找到对应值,开始检测下一个值
//                first = second + 1;
//                second = first + 1;
//                if (first < size && second >= size) {
//                    return false;
//                }
//            } else {
//                second++;
//                if (second >= size) {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }

    // 第四次未通过的测试用例：
    // 输入
    //s =
    //"([)]"
    //输出
    //true
    //预期结果
    //false
//    bool isValid(std::string s) {
//        std::unordered_map<char, char> hashmap;
//
//        size_t size = s.size();
//        if (size == 1) {
//            return false;
//        }
//
//        hashmap.insert({'(', ')'});
//        hashmap.insert({'{', '}'});
//        hashmap.insert({'[', ']'});
//        const char *s_ctr = s.c_str();
//        // 使用双指针的方法，first 和second一起遍历，开始first 指向第一个字符，second指向第二个字符
//        // 当first 为 ( [ { 时暂停对first 的遍历，second向后遍历直到遍历到匹配的) ] } 向后遍历first,将second指向first 的下一个字符...
//        int first = 0;
//        int second = 1;
//        // 找到键值
//        while (second <= size - 1) {
//            if (hashmap.find(s_ctr[first]) != hashmap.end() && hashmap[s_ctr[first]] == s_ctr[second]) {
//                // 找到对应值,开始检测下一个值,下一个first 应该是上一个first 之后的下一个{ [ (
//                first++;
//                while (first < size && hashmap.find(s_ctr[first]) == hashmap.end()){
//                    first++;
//                }
//                second = first + 1;
//                if (first<size && second >= size) {
//                    return false;
//                }
//            } else {
//                second++;
//                if (second >= size) {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }

    // 第五次忍无可忍之开摆，我是废物§(*￣▽￣*)§
    // 官方题解
    // 使用栈真是简单得很啊
//    bool isValid(std::string s) {
//        int n = s.size();
//        if (n % 2 == 1) {
//            return false;
//        }
//
//        std::unordered_map<char, char> pairs = {
//                {')', '('},
//                {']', '['},
//                {'}', '{'}
//        };
//        std::stack<char> stk;
//        for (char ch: s) {
//            if (pairs.count(ch)) {
//                // 如果是右括号
//                if (stk.empty() || stk.top() != pairs[ch]) {
//                    return false;
//                }
//                stk.pop();
//            } else {
//                // 将左括号入栈
//                stk.push(ch);
//            }
//        }
//
//        // 最后检查栈是否为空
//        return stk.empty();
//    }

    bool isValid(std::string s) {
        size_t size = s.size();
        if (size % 2 == 1) {
            return false;
        }

        // 定义一个hashMap
        std::unordered_map<char, char> hashmap;
        hashmap.insert({{'(', ')'}, {'{', '}'}, {'[', ']'}});

        // 定义一个栈
        std::stack<char> stk;
        // 遍历s
        for (char c: s) {
            if (hashmap.count(c)) {
                // 如果是左括号，入栈
                stk.push(c);

            } else {
                // 如果是右括号，进行检验
                if (stk.empty() || hashmap[stk.top()] != c) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};

#endif //ALGORITHM_TEST_20_H
