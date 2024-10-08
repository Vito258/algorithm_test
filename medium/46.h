//
// Created by 860122023 on 2024/10/8.
//

#ifndef ALGORITHM_TEST_46_H
#define ALGORITHM_TEST_46_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// 全排列
class Solution {
public:
    // 完犊子，根本没有思路
//    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
//        std::vector<std::vector<int>> result;
//
//        int n = nums.size();
//        // 排除特殊情况
//        if (n == 0) {
//            return {};
//        }
//
//        if (n == 1) {
//            return {nums};
//        }
//
//        // 升序排序
//        std::sort(nums.begin(), nums.end());
//        result.push_back(nums);
//
//        // 在升序的基础上，遍历各种可能性
//        return result;
//    }

    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        permuteHelper(nums,0,result);
        return result;
    }

    // 生成所有全排列的函数
    void permuteHelper(std::vector<int> &nums, int start, std::vector<std::vector<int>> &result) {
        if (start == nums.size() - 1) {
            // 当只剩下一个元素时，将当前排列添加到结果中
            result.push_back(nums);
        } else {
            for (int i = start; i < nums.size(); ++i) {
                // 交换元素
                std::swap(nums[start], nums[i]);

                // 递归生成后续排列
                permuteHelper(nums, start + 1, result);

                // 回溯，恢复原状
                std::swap(nums[start], nums[i]);
            }
        }
    }

};

#endif //ALGORITHM_TEST_46_H
