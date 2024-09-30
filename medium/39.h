//
// Created by 860122023 on 2024/9/30.
//

#ifndef ALGORITHM_TEST_39_H
#define ALGORITHM_TEST_39_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* 组合总和 */
class Solution {
public:
    // 自己尝试去做，根本没思路可能性太多了（┭┮﹏┭┮)
//    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
//        int size = candidates.size();
//        // 排除特殊情况
//        if(size == 0){
//            return {};
//        }
//        std::vector<std::vector<int>> result;
//        std::sort(candidates.begin(),candidates.end());
//
//        for(int i=0;i<size;i++){
//            if(candidates[i] == target){
//                result.push_back({target});
//            }
//            if(candidates[i] > target){
//                break;
//            }
//            if(candidates[i] < target){
//                if(target % candidates[i] != 0){
//
//                }else{
//                    std::vector<int> temp;
//                    for(int j=0;j<target/candidates[i];j++){
//                      temp.push_back(target);
//                    }
//                    result.push_back(temp);
//                }
//            }
//        }
//    }

    // 对于所有搜索可行性的解，我们都可以通过搜索回溯的方式解决
    // 官方题解1：
    void dfs(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& ans, std::vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
#endif //ALGORITHM_TEST_39_H
