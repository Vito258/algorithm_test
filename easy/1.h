//
// Created by 860122023 on 2024/8/7.
//
#include <vector>
#include <iostream>

/*1.两数之和*/
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      for(int i=0;i<nums.size();i++){
          for(int j=(nums.size()-1);j>i;j--){
             if(nums[i] + nums[j] == target){
                 return {i,j};
             }
          }
      }
        return std::vector<int>();
    }
};