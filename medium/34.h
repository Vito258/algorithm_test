//
// Created by 860122023 on 2024/9/27.
//

#ifndef ALGORITHM_TEST_34_H
#define ALGORITHM_TEST_34_H
#include <vector>
#include <string>
#include <iostream>

/* 在排序数组中查找元素第一个和最后一个位置 */
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums 是一个非递减数组
// -109 <= target <= 109
// 要求算法复杂度为log(n)，一般要求这个就是要使用二分

class Solution {
public:
    // 独立去做,写完才发现算法复杂度为n...
    // 出现了数组越界错误
//    std::vector<int> searchRange(std::vector<int>& nums, int target) {
//        int size = nums.size();
//
//        // 排除特殊情况
//        if(size == 0){
//            return {-1,-1};
//        }
//
//        int left = 0, right = size - 1;
//        while(left <= right){
//            if(nums[left] != target){
//                left++;
//            }
//            if(nums[right] != target){
//                right--;
//            }
//            if(nums[left] == target && nums[right] == target) break;
//        }
//        if(left > right){
//            return {-1,-1};
//        }else{
//            return {left,right};
//        }
//    }

    // 改为使用二分,通过！！！
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int size = nums.size();
        // 排除特殊情况
        if(size == 0){
            return {-1,-1};
        }
        int left = findLeft(nums,target);
        int right = findRight(nums,target);
        if(left > right){
            return {-1,-1};
        }else{
            return {left,right};
        }
    }
    // 主要向左寻找
    int findLeft(std::vector<int> nums,int target){
        int left = 0,right = nums.size()- 1;
        int result = -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                right = mid - 1;
                result = mid;
            } else if(nums[mid] > target){
                right = mid -1 ;
            }else{
                left = mid+1;
            }
        }
        return result;
    }
    // 主要向右寻找
    int findRight(std::vector<int> nums,int target){
        int left = 0,right = nums.size()- 1;
        int result = -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                left = mid + 1;
                result = mid;
            } else if(nums[mid] > target){
                right = mid -1 ;
            }else{
                left = mid+1;
            }
        }
        return result;
    }
};
#endif //ALGORITHM_TEST_34_H
