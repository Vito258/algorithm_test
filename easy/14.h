//
// Created by 860122023 on 2024/8/16.
//

#ifndef ALGORITHM_TEST_14_H
#define ALGORITHM_TEST_14_H

/* 最长公共前缀 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    // 自己写的，通过，算是横向扫描
//    std::string longestCommonPrefix(std::vector<std::string>& strs) {
//        size_t size = strs.size();
//        //处理特殊情况
//        //1、数组为空
//        if(size == 0){
//            return "";
//        }
//        //2、数组中只有一个元素
//        else if(size == 1){
//            return strs[0];
//        }
//
//        std::string result;
//        int max_index = 0;
//        // 遍历字符串
//        // 使用lambda 表达式调查数组中最小的字符串长度
//        auto min_it = std::min_element(strs.begin(), strs.end(),
//                                       [](const std::string& a, const std::string& b) {
//                                           return a.size() < b.size();
//                                       });
//        int min_length = min_it->size();
//        outer_loop:
//        while (max_index<=min_length){
//            for(int i=0; i< size - 1; i++){
//                if(strs[i][max_index] == strs[i+1][max_index]){
//                    if(i == size -2){
//                        max_index++;
//                    }
//                }else{
//                    goto exit_all_loops;
//                }
//            }
//        }
//        exit_all_loops:
//        if(max_index != 0){
//            return strs[0].substr(0,max_index);
//        }else{
//            return "";
//        }
//    }

      // 官方题解2，纵向扫描
      // 从前往后遍历所有字符串的每一列，比较相同列上的字符是否相同，如果相同则继续对下一列进行比较，如果不相同则当前列不再属于公共前缀，当前列之前的部分为最长公共前缀。
      std::string longestCommonPrefix(std::vector<std::string>& strs) {
            if (!strs.size()) {
                return "";
            }
            int length = strs[0].size();
            int count = strs.size();
            for (int i = 0; i < length; ++i) {
                char c = strs[0][i];
                for (int j = 1; j < count; ++j) {
                    if (i == strs[j].size() || strs[j][i] != c) {
                        return strs[0].substr(0, i);
                    }
                }
            }
            return strs[0];
        }
};
#endif //ALGORITHM_TEST_14_H
