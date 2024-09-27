//
// Created by 860122023 on 2024/9/27.
//

#ifndef ALGORITHM_TEST_35_H
#define ALGORITHM_TEST_35_H
#include <iostream>
#include <vector>
#include <string>

/* 搜索插入位置 */
// 必须使用时间复杂度为 O(log n) 的算法。
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0){
            return 0;
        }

        int left = 0,right = size - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }else if (nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        // 没找到值，返回必须插入位置索引
        return left + (right - left) /2;
    }
};
#endif //ALGORITHM_TEST_35_H
