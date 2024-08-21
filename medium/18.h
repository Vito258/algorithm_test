//
// Created by 111 on 2024/8/21.
//

#ifndef ALGORITHM_TEST_18_H
#define ALGORITHM_TEST_18_H

#include <iostream>
#include <vector>
#include <algorithm>

/* 四数之和 */
class Solution {
public:

    //  第一次自己尝试写,有重复元素
//    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
//        // 排序
//        std::sort(nums.begin(), nums.end());
//
//        size_t size = nums.size();
//
//        std::vector<std::vector<int>> result;
//        // 锚定两个值 + 双指针法
//        for (int i = 0; i < (size - 3); i++) {
//            // 跳过重复元素
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            for (int j = (i + 1); j < (size - 2); j++) {
//                //元素重复，跳过
//                if (j > (i + 1) && nums[j] == nums[j - 1]) {
//                    continue;
//                }
//
//                // 使用索引，符合现代c++ 的风格
//                int left = j + 1;
//                int right = size - 1;
//                int sum;
//                while (left < right) {
//                    sum = nums[i] + nums[j] + nums[left] + nums[right];
//                    if (sum > target) {
//                        right--;
//                    } else if (sum < target) {
//                        left++;
//                    } else {
//                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
//                        left++;
//                        right--;
//                    }
//
//                    // 跳过重复元素
//                    while (left < right && left > j+1 && nums[left] == nums[left - 1]) {
//                        left++;
//                    }
//
//                    while (left < right && right < size -1 && nums[right] == nums[right + 1]) {
//                        right--;
//                    }
//                }
//            }
//        }
//        return result;
//    }

    //  第二次提交,sum 超出int 限制 预期输入[1000000000,1000000000,1000000000,1000000000]
//    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
//        // 排序
//        std::sort(nums.begin(), nums.end());
//
//        size_t size = nums.size();
//        if(size < 4){
//            return {};
//        }
//        std::vector<std::vector<int>> result;
//        // 锚定两个值 + 双指针法
//        for (int i = 0; i < (size - 3); i++) {
//            // 跳过重复元素
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            for (int j = (i + 1); j < (size - 2); j++) {
//                //元素重复，跳过
//                if (j > (i + 1) && nums[j] == nums[j - 1]) {
//                    continue;
//                }
//
//                // 使用索引，符合现代c++ 的风格
//                int left = j + 1;
//                int right = size - 1;
//                long sum;
//                while (left < right) {
//                    sum = nums[i] + nums[j] + nums[left] + nums[right];
//                    if (sum > target) {
//                        right--;
//                    } else if (sum < target) {
//                        left++;
//                    } else {
//                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
//                        left++;
//                        right--;
//                    }
//
//                    // 跳过重复元素
//                    while (left < right && left > j+1 && nums[left] == nums[left - 1]) {
//                        left++;
//                    }
//
//                    while (left < right && right < size -1 && nums[right] == nums[right + 1]) {
//                        right--;
//                    }
//                }
//            }
//        }
//        return result;
//    }

    // 使用逐个比较的方式：不直接计算总和，而是通过逐个比较的方式来判断是否达到目标值。
    // 依然报错（shit！！！！！！ 我算是知道为啥这道题通过率这么低了
//    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
//        // 排序
//        std::sort(nums.begin(), nums.end());
//
//        size_t size = nums.size();
//        if(size < 4){
//            return {};
//        }
//        std::vector<std::vector<int>> result;
//        // 锚定两个值 + 双指针法
//        for (int i = 0; i < (size - 3); i++) {
//            // 跳过重复元素
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            for (int j = (i + 1); j < (size - 2); j++) {
//                //元素重复，跳过
//                if (j > (i + 1) && nums[j] == nums[j - 1]) {
//                    continue;
//                }
//
//                // 使用索引，符合现代c++ 的风格
//                int left = j + 1;
//                int right = size - 1;
//                int sum;
//                int currentSum;
//                while (left < right) {
//                    sum = nums[i] + nums[j] ;
//                    currentSum = nums[left] + nums[right];
//                    if (sum + currentSum > target) {
//                        right--;
//                    } else if (sum + currentSum < target) {
//                        left++;
//                    } else {
//                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
//                        left++;
//                        right--;
//                    }
//
//                    // 跳过重复元素
//                    while (left < right && left > j+1 && nums[left] == nums[left - 1]) {
//                        left++;
//                    }
//
//                    while (left < right && right < size -1 && nums[right] == nums[right + 1]) {
//                        right--;
//                    }
//                }
//            }
//        }
//        return result;
//    }

    // 通过转换为long long 类型的方式
    // 可算通过了，我上早八！！！！！！！！！
    // 差不多，官方题解也是这个思路
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
        // 排序
        std::sort(nums.begin(), nums.end());

        size_t size = nums.size();
        if(size < 4){
            return {};
        }
        std::vector<std::vector<int>> result;
        // 锚定两个值 + 双指针法
        for (int i = 0; i < (size - 3); i++) {
            // 跳过重复元素
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = (i + 1); j < (size - 2); j++) {
                //元素重复，跳过
                if (j > (i + 1) && nums[j] == nums[j - 1]) {
                    continue;
                }

                // 使用索引，符合现代c++ 的风格
                int left = j + 1;
                int right = size - 1;
                while (left < right) {
                    // 避免整数溢出
                    long long sum_ij = static_cast<long long>(nums[i]) + nums[j];
                    long long sum_lr = static_cast<long long>(nums[left]) + nums[right];

                    if (sum_ij > INT_MAX - sum_lr || sum_ij < INT_MIN - sum_lr) {
                        // 如果加起来会溢出，则直接跳过
                        break;
                    }

                    long long total_sum = sum_ij + sum_lr;

                    if (total_sum > target) {
                        right--;
                    } else if (total_sum < target) {
                        left++;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }

                    // 跳过重复元素
                    while (left < right && left > j+1 && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && right < size -1 && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

#endif //ALGORITHM_TEST_18_H
