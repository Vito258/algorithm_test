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
// 与1 的区别就是数组中的每个元素只可以使用一次，且不包含重复的组合
class Solution {
public:
    // 失败
//    void dfs(std::vector<int> candinate, int target, int index, std::vector<int> combine,
//             std::vector<std::vector<int>> &ans) {
//        if(index == candinate.size()){
//            return;
//        }
//        if (target == 0) {
//            ans.emplace_back(combine);
//            return;
//        }
//        // 不选择当前元素
//        dfs(candinate, target, index + 1, combine, ans);
//
//        if (target - candinate[index] >= 0) {
//            combine.emplace_back(candinate[index]);
//            candinate.erase(candinate.begin()+index);
//            dfs(candinate, target - candinate[index], index-1, combine, ans);
//            combine.pop_back();
//        }
//    }
//
//    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
//        std::vector<std::vector<int>> ans;
//        std::vector<int> combine;
//        dfs(candidates, target, 0, combine, ans);
//        return ans;
//    }

    // 优化之后的代码
    // 优化要点
    //  排序：先对 candidates 进行排序，便于后续去重。
    //  剪枝：在递归过程中跳过重复的元素。
    //  递归参数：使用 start 参数来记录当前搜索的起始位置，确保每个元素只被使用一次。
    //  这样可以有效地去除重复组合，并且保证每个元素只被使用一次。
    void dfs(const std::vector<int> &candidates, int target, int start, std::vector<int> &combine,
             std::vector<std::vector<int>> &ans) {
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // 剪枝：跳过重复元素
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (target - candidates[i] >= 0) {
                combine.emplace_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1, combine, ans);  // 下一个元素从 i+1 开始
                combine.pop_back();
            }
        }
    }

// 主函数
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> combine;

        // 先排序，方便去重
        std::sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0, combine, ans);

        return ans;
    }
};

#endif //ALGORITHM_TEST_40_H
