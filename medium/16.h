//
// Created by 860122023 on 2024/8/20.
//

#ifndef ALGORITHM_TEST_16_H
#define ALGORITHM_TEST_16_H

#include <iostream>
#include <vector>
#include <algorithm>

/* 最接近的三数之和 */
class Solution {
public:
    // 排序+双指针的方式
    // 错误：未通过测试用例[-4,2,2,3,3,3] target = 0
    // 输出:1
    // 预期结果:0
//    int threeSumClosest(std::vector<int> &nums, int target) {
//        //排序
//        std::sort(nums.begin(), nums.end());
//        size_t size = nums.size();
//        int min = INT_MAX;
//        int result = 0;
//        for (int i = 0; i < (size - 2); i++) {
//            int i_value = nums[i];
//            const int *left = &nums[i + 1];
//            const int *right = &nums[size - 1];
//            int sum = 0;
//            int difference = 0;
//
//            while (left < right) {
//                sum = i_value + *left + *right;
//                if (sum > target) {
//                    difference = sum - target;
//                } else if (sum < target) {
//                    difference = target - sum;
//                } else if(sum == target){
//                    return sum;
//                }
//
//                if (difference < min) {
//                    min = difference;
//                    result = sum;
//                }
//                while (left < right && *left == *(left + 1)) {
//                    left++;
//                }
//                while (left < right && *right == *(right - 1)) {
//                    right--;
//                }
//                left++;
//                right--;
//            }
//        }
//        return result;
//    }

    // 官方题解：
    // 使用索引 替换指针更接近现代c++的做法
//    int threeSumClosest(std::vector<int> &nums, int target) {
//        std::sort(nums.begin(), nums.end());
//        size_t size = nums.size();
//
//        if (size < 3) {
//            throw std::invalid_argument("Input vector must have at least 3 elements.");
//        }
//
//        int min_diff = INT_MAX;
//        int result = 0;
//
//        for (int i = 0; i < static_cast<int>(size - 2); i++) {
//            // 跳过重复元素
//            if (i > 0 && nums[i] == nums[i-1]) {
//                continue;
//            }
//
//            int left = i + 1;
//            int right = static_cast<int>(size - 1);
//
//            while (left < right) {
//                int sum = nums[i] + nums[left] + nums[right];
//                // 取绝对值
//                int diff = std::abs(sum - target);
//
//                if (diff < min_diff) {
//                    min_diff = diff;
//                    result = sum;
//                }
//
//                if (sum < target) {
//                    left++;  // 增加较小的值
//                } else if (sum > target) {
//                    right--;  // 减少较大的值
//                } else {
//                    return sum;  // 找到了精确匹配
//                }
//
//                // 跳过重复元素
//                while (left < right && left > i + 1 && nums[left] == nums[left - 1]) {
//                    left++;
//                }
//                while (left < right && right < static_cast<int>(size - 1) && nums[right] == nums[right + 1]) {
//                    right--;
//                }
//            }
//        }
//        return result;
//    }

    // 未通过的测试用例：nums = [-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1]
    // target = -8
    // 输出： -11
    // 预期结果： -7
//    int threeSumClosest(std::vector<int> &nums, int target) {
//        //排序
//        std::sort(nums.begin(), nums.end());
//        size_t size = nums.size();
//
//        int min_diff = INT_MAX;
//        int result = 0;
//        for (int i = 0; i < (size - 2); i++) {
//            // 跳过重复元素
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//
//            int i_value = nums[i];
//            const int *left = &nums[i + 1];
//            const int *right = &nums[size - 1];
//            int sum = 0;
//            int difference = 0;
//
//            while (left < right) {
//                sum = i_value + *left + *right;
//                int diff = std::abs(sum-target);
//
//                if (diff < min_diff) {
//                    min_diff = diff;
//                    result = sum;
//                }
//
//                if(sum > target){
//                    right--;
//                }else if(sum < target){
//                    left++;
//                }else{
//                    return sum;
//                }
//
//                // 跳过重复元素
//                while (left < right && left > &nums[i + 1] && *left == *(left+1)) {
//                    left++;
//                }
//                while (left < right && right < &nums[size -1] && *right == *(right + 1)) {
//                    right--;
//                }
//            }
//        }
//        return result;
//    }

    int threeSumClosest(std::vector<int> &nums, int target) {
        //排序
        std::sort(nums.begin(), nums.end());
        size_t size = nums.size();

        int min_diff = INT_MAX;
        int result = 0;
        for (int i = 0; i < (size - 2); i++) {
            // 跳过重复元素
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int i_value = nums[i];
            const int *left = &nums[i + 1];
            const int *right = &nums[size - 1];
            int sum = 0;
            int difference = 0;

            while (left < right) {
                sum = i_value + *left + *right;
                int diff = std::abs(sum-target);

                if (diff < min_diff) {
                    min_diff = diff;
                    result = sum;
                }

                if(sum > target){
                    right--;
                }else if(sum < target){
                    left++;
                }else{
                    return sum;
                }

                // 重点：跳过重复元素
                while (left < right && left > &nums[i + 1] && *left == *(left-1)) {
                    left++;
                }
                while (left < right && right < &nums[size -1] && *right == *(right + 1)) {
                    right--;
                }
            }
        }
        return result;
    }
};

#endif //ALGORITHM_TEST_16_H
