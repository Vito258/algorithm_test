//
// Created by 860122023 on 2024/10/8.
//

#ifndef ALGORITHM_TEST_45_H
#define ALGORITHM_TEST_45_H

// 跳跃游戏Ⅱ
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

class Solution {
public:
    // 报错，超出时间限制
//    int jump(std::vector<int> &nums) {
//        int n = nums.size();
//        int index = 0;
//        int count = 0;
//        while(index < n-1){
//           int step =  jump_step(index,nums);
//           index += step;
//           count++;
//        }
//        return count;
//    }

    // 返回最大步数内的下个索引哪个值最大，也就是应该跳几步
//    int jump_step(int index, std::vector<int> &nums) {
//        int max_step = nums[index];
//        if (max_step == 0) {
//            return 0;
//        }
//        if (max_step == 1) {
//            return 1;
//        }
//
//        // 如果可以跳到末尾，直接返回
//        if(index + max_step >= nums.size() -1){
//            return nums.size();
//        }
//
//        int max_index = 0;
//        int max_num = 0;
//        for (int i = 1; i <= max_step; i++) {
//            if(index + i >= nums.size())
//                break;
//            if(nums[index + i] > max_num){
//                max_num = nums[index + i];
//                max_index = i;
//            }
//            if(i == max_step && nums[index + i] == max_num){
//                return max_step;
//            }
//        }
//        return max_index;
//    }

    // 优化之后的代码，使用贪心算法：
    // 当前算法的复杂度为n，需要遍历vector 中的每个元素，观察其能到达的最末尾的节点
    // 当 i 是落脚点之一时，step++, index == n-1 时不计入，index == 0 时,step++ 一定执行
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int steps = 0;      // 当前跳跃次数
        int maxReach = 0;   // 当前能到达的最大位置
        int end = 0;        // 当前跳跃的终点

        for (int i = 0; i < n - 1; i++) {  // 不需要检查最后一个位置
            // 在这里作比较，比较上一个索引所能到达的最远重点和当前索引所能抵达的最远重点
            maxReach = std::max(maxReach, i + nums[i]);
            if (i == end) {  // 到达当前跳跃的终点
                steps++;  // 增加一次跳跃
                end = maxReach;  // 更新跳跃终点
                if (end >= n - 1) break;  // 如果已经可以达到最后的位置，则提前结束
            }
        }
        return steps;
    }
};

#endif //ALGORITHM_TEST_45_H
