//
// Created by 860122023 on 2024/9/9.
//

#ifndef ALGORITHM_TEST_27_H
#define ALGORITHM_TEST_27_H

#include <iostream>
#include <vector>

/* 移除元素 */
// 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100
class Solution {
public:
    // 自己尝试去写，使用双指针的方法 -通过！！
//    int removeElement(std::vector<int> &nums, int val) {
//        size_t size = nums.size();
//        if (size == 0) {
//            return size;
//        }
//        int fast = 0, slow = 0;
//        while (fast < size) {
//            if (nums[fast] != val && nums[slow] == val) {
//                nums[slow] = nums[fast];
//                nums[fast] = val;
//                slow++;
//            } else if (nums[fast] == val && nums[slow] != val) {
//                slow++;
//            } else if (nums[fast] != val && nums[slow] != val){
//                slow++;
//            }
//            fast++;
//
//        }
//        return slow;
//    }

    // 上面的那种方法至多会遍历数组两次，可以继续优化
    // 官方题解2 双指针优化
    int removeElement(std::vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
};

#endif //ALGORITHM_TEST_27_H
