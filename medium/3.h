//
// Created by 860122023 on 2024/8/8.
//

#ifndef ALGORITHM_TEST_3_H
#define ALGORITHM_TEST_3_H
#include <iostream>
#include <string>
#include <unordered_set>

/* 无重复字符的最长字串 */
class Solution {
public:
    // 第一版，未测试通过（悲
//    int lengthOfLongestSubstring(std::string s) {
//        const size_t size = s.size();
//        const char* char_array = s.c_str();
//
//        //1、使用两个指针 left 和 right 来表示窗口的左右边界，初始时这两个指针都指向字符串的起始位置。
//        const char* left = char_array;
//        const char* right = char_array;
//
//        //2、使用hash_set记录当前窗口内出现过的字符
//        std::unordered_set<char> hash_set ;
//
//        //3、当 right 指针所指向的字符不在哈希集合中时，将其加入哈希集合，并移动 right 指针到下一个位置。
//        //4、如果 right 指针所指向的字符已经在哈希集合中，那么就从哈希集合中移除 left 指针所指向的字符，并移动 left 指针到下一个位置。
//        int maxLength = 0;
//        for(int i=0; i<size; i++){
//           auto it = hash_set.find(*right);
//
//           if(it == hash_set.end()){
//               hash_set.insert(*right);
//               right = &char_array[i+1];
//           }else{
//               hash_set.erase(*left);
//               left = &char_array[i+1];
//           }
//
//           int length = right - left;
//           if(length > maxLength){
//               maxLength = length;
//           }
//        }
//        return maxLength;
//    }

    int lengthOfLongestSubstring(std::string s) {
        const size_t size = s.size();
        if (size == 0) return 0; // 处理空字符串的情况

        const char* left = s.c_str();
        const char* right = s.c_str();

        std::unordered_set<char> hash_set;

        int maxLength = 0;

        while (right < s.c_str() + size) { // 确保不会越界
            auto it = hash_set.find(*right);

            if (it == hash_set.end()) {
                hash_set.insert(*right);
                ++right; // 移动 right 到下一个位置
            } else {
                hash_set.erase(*left);
                ++left; // 移动 left 到下一个位置
            }

            int length = right - left;
            if (length > maxLength) {
                maxLength = length;
            }
        }
        return maxLength;
    }
};
#endif //ALGORITHM_TEST_3_H
