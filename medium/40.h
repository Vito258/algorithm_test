//
// Created by 860122023 on 2024/9/30.
//

#ifndef ALGORITHM_TEST_40_H
#define ALGORITHM_TEST_40_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 组合总和2
// 与1 的区别就是数组中的每个元素只可以使用一次
class Solution {
public:
    void dfs(std::vector<int> candinate, int target, int index, std::vector<int> combine,
             std::vector<std::vector<int>> &ans) {
        if (index == candinate.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 不选择当前元素
        dfs(candinate, target, index + 1, combine, ans);

        if (target - candinate[index] >= 0) {
            combine.emplace_back(candinate[index]);
            dfs(candinate, target - candinate[index], index, combine, ans);
            combine.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> combine;
        dfs(candidates, target, 0, combine, ans);
        return ans;
    }
};

#endif //ALGORITHM_TEST_40_H
