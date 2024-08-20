//
// Created by 860122023 on 2024/8/20.
//

#ifndef ALGORITHM_TEST_17_H
#define ALGORITHM_TEST_17_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
/* 电话的号码组合 */
class Solution {
public:

    // 自己尝试去写，虽然通过了但是消耗内存太大
//    std::vector<std::string> letterCombinations(std::string digits) {
//        // 创建hashmap 储存值
//        std::unordered_map<char, std::vector<std::string>> myMap;
//
//        // 插入键值对
//        myMap['2'] = {"a","b","c"};
//        myMap['3'] = {"d","e","f"};
//        myMap['4'] = {"g","h","i"};
//        myMap['5'] = {"j","k","l"};
//        myMap['6'] = {"m","n","o"};
//        myMap['7'] = {"p","q","r","s"};
//        myMap['8'] = {"t","u","v"};
//        myMap['9'] = {"w","x","y","z"};
//
//        size_t length = digits.length();
//        std::vector<std::string> result;
//        // 分情况
//        if (length == 0) {
//            return {};
//        }else if(length == 1){
//            return myMap[digits[0]];
//        }else if (length == 2){
//            for(int i = 0; i<myMap[digits[0]].size(); i++){
//                for(int j=0; j< myMap[digits[1]].size(); j++){
//                    std::string temp = myMap[digits[0]][i]+myMap[digits[1]][j];
//                    result.push_back(temp);
//                }
//            }
//        }else if(length == 3){
//            for(int i = 0; i<myMap[digits[0]].size(); i++){
//                for(int j=0; j< myMap[digits[1]].size(); j++){
//                    for(int k=0; k< myMap[digits[2]].size(); k++){
//                        std::string temp = myMap[digits[0]][i]+myMap[digits[1]][j]+myMap[digits[2]][k];
//                        result.push_back(temp);
//                    }
//                }
//            }
//        }else if(length == 4){
//            for(int i = 0; i<myMap[digits[0]].size(); i++){
//                for(int j=0; j< myMap[digits[1]].size(); j++){
//                    for(int k=0; k< myMap[digits[2]].size(); k++){
//                        for(int l=0; l< myMap[digits[3]].size(); l++) {
//                            std::string temp = myMap[digits[0]][i] + myMap[digits[1]][j] + myMap[digits[2]][k] + myMap[digits[3]][l];
//                            result.push_back(temp);
//                        }
//                    }
//                }
//            }
//        }
//        return result;
//    }

    // 使用递归的方式,本质上是一样的但是减少了重复的代码量
//    std::vector<std::string> letterCombinations(std::string digits) {
//        // 创建hashmap 储存值
//        std::unordered_map<char, std::vector<std::string>> myMap = {
//                {'2', {"a", "b", "c"}},
//                {'3', {"d", "e", "f"}},
//                {'4', {"g", "h", "i"}},
//                {'5', {"j", "k", "l"}},
//                {'6', {"m", "n", "o"}},
//                {'7', {"p", "q", "r", "s"}},
//                {'8', {"t", "u", "v"}},
//                {'9', {"w", "x", "y", "z"}}
//        };
//
//        if (digits.empty()) {
//            return {};
//        }
//
//        std::vector<std::string> result;
//        // 使用lambda 表达式 自定义函数
//        std::function<void(size_t, std::string)> helper = [&](size_t index, std::string current) {
//            if (index == digits.size()) {
//                result.push_back(current);
//                return;
//            }
//
//            const auto& letters = myMap[digits[index]];
//            for (const auto& letter : letters) {
//                helper(index + 1, current + letter);
//            }
//        };
//
//        // 给index 和current 附上初始值0 以及“” 并执行helper函数
//        helper(0, "");
//        return result;
//    }

    // 官方题解，也是通过递归（回溯）的方法
//    std::vector<std::string> letterCombinations(std::string digits) {
//        std::vector<std::string> combinations;
//        if (digits.empty()) {
//            return combinations;
//        }
//        std::unordered_map<char, std::string> phoneMap{
//                {'2', "abc"},
//                {'3', "def"},
//                {'4', "ghi"},
//                {'5', "jkl"},
//                {'6', "mno"},
//                {'7', "pqrs"},
//                {'8', "tuv"},
//                {'9', "wxyz"}
//        };
//        std::string combination;
//        backtrack(combinations, phoneMap, digits, 0, combination);
//        return combinations;
//    }
//
//    void backtrack(std::vector<std::string>& combinations, const std::unordered_map<char, std::string>& phoneMap, const std::string& digits, int index, std::string& combination) {
//        if (index == digits.length()) {
//            combinations.push_back(combination);
//        } else {
//            char digit = digits[index];
//            const std::string& letters = phoneMap.at(digit);
//            for (const char& letter: letters) {
//                combination.push_back(letter);
//                backtrack(combinations, phoneMap, digits, index + 1, combination);
//                combination.pop_back();
//            }
//        }
//    }

    // 看题解之后再尝试自己写一遍：
    std::vector<std::string> letterCombinations(std::string digits) {
        // 创建hashmap 储存值
        std::unordered_map<char, std::vector<std::string>> myMap = {
                {'2', {"a", "b", "c"}},
                {'3', {"d", "e", "f"}},
                {'4', {"g", "h", "i"}},
                {'5', {"j", "k", "l"}},
                {'6', {"m", "n", "o"}},
                {'7', {"p", "q", "r", "s"}},
                {'8', {"t", "u", "v"}},
                {'9', {"w", "x", "y", "z"}}
        };

        if (digits.empty()) {
            return {};
        }

        std::vector<std::string> result;
        //创建helper 函数
        std::function<void(size_t,std::string)> helper = [&](size_t index,std::string current){
            // 当前digits 所有的元素已经 遍历了一遍，可以将当前的结果储存到result
            if(index == digits.size()){
                result.push_back(current);
                return ;
            }
            const auto letters = myMap[digits[index]];
            for (std::string letter : letters){
                helper(index+1, current + letter);
            }
        };

        helper(0,"");
        return result;
    }
};

#endif //ALGORITHM_TEST_17_H
