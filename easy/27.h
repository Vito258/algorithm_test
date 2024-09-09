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
    // 自己尝试去写，使用双指针的方法
    int removeElement(std::vector<int> &nums, int val) {
        size_t size = nums.size();
        if (size == 0) {
            return size;
        }
        int fast = 0, slow = 0;
        while (fast < size) {
            if(nums[fast] == val){

            }else if(nums[fast - 1] == val){
                // 交换数值
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
            }
            fast++;
        }

        for(int i: nums){
            std::cout<<i<<std::endl;
        }
        return slow;
    }
};

#endif //ALGORITHM_TEST_27_H
