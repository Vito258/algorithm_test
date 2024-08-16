//
// Created by 860122023 on 2024/8/16.
//

#ifndef ALGORITHM_TEST_15_H
#define ALGORITHM_TEST_15_H

#include <iostream>
#include <vector>

/* 找出数组中的三元组 */
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        size_t size = nums.size();
        for (int i = 0; i < size; i++) {
            // 再寻找nums[j] + num[k] = ruler_i
            int ruler_i = -nums[i];
            
        }
    }
};

#endif //ALGORITHM_TEST_15_H
