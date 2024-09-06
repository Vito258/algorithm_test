//
// Created by 860122023 on 2024/9/6.
//

#ifndef ALGORITHM_TEST_26_H
#define ALGORITHM_TEST_26_H

#include <iostream>
#include <vector>

/* 删除有序数组中的重复项 */
// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// nums 已按 非严格递增 排列
class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        size_t size = nums.size();
        if (size < 2){
            return size;
        }
        int elementRem = 105;
        for(int i=0;i<size; i++){
            if(nums[i] == elementRem){
                nums.erase(nums.begin() + i);
            }else {
                elementRem = nums[i];
            }
        }
        return nums.size();
    }
};

#endif //ALGORITHM_TEST_26_H
