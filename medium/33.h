//
// Created by 860122023 on 2024/9/24.
//

#ifndef ALGORITHM_TEST_33_H
#define ALGORITHM_TEST_33_H


#include <vector>
#include <iostream>

/* 搜索旋转排序数组 */
// 必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// nums 中的每个值都 独一无二
// 题目数据保证 nums 在预先未知的某个下标上进行了旋转
// -104 <= target <= 104
class Solution {
public:
    // 尝试自己使用二分法
    int search(std::vector<int> &nums, int target) {
        // 旋转序列可以看为两个升序序列对接，且第二个序列的最大值小于第一个序列的最小值
        // left 为第一个序列的最小值，right 为第二个序列的最大值
        int left = 0, right = nums.size() - 1;
        int middle = (left + right)/2;

        // 判断target 是在第一个还是第二个序列中
        if (target > nums[right]) {
            // 在第一序列
            while(nums[middle] < nums [right]){
                right--;
                middle = (left + right)/2;
            }

        } else if (target < nums[right]) {
            // 在第二序列
        } else {
            // 处理特殊情况
            return right;
        }
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) return middle;

            // middle 属于第二个序列
            if (nums[middle] < nums[left]) {
                if (nums[middle] < target) {
                    if (nums[right] < target) {
                        right = middle - 1;
                    } else if (nums[right] > target) {
                        left = middle + 1;
                    } else {
                        return right;
                    }
                }

                if (nums[middle] > target) {
                    right = middle - 1;
                }
            }

            // middle 属于第一个序列
            if (nums[middle] > nums[left]) {
                if (nums[middle] > target) {
                    right = middle - 1;
                }
                if (nums[middle] < target) {
                    left = middle + 1;
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};

#endif //ALGORITHM_TEST_33_H
