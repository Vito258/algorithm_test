//
// Created by 860122023 on 2024/8/16.
//

#ifndef ALGORITHM_TEST_15_H
#define ALGORITHM_TEST_15_H

#include <iostream>
#include <vector>
#include <algorithm>

/* 找出数组中的三元组 */
class Solution {
public:
    // 第一次尝试，会产生重复的三元数组
//    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
//        size_t size = nums.size();
//
//        std::vector<std::vector<int>> result;
//        // 通过 for循环的方法锚定两个数
//        for (int i = 0; i < size-2; i++) {
//          for(int j = i+1; j<size -1; j++){
//             int ruler = -(nums[i]+nums[j]);
//             for(int k = j+1; k<size; k++){
//                 if(nums[k] == ruler){
//                     result.push_back({nums[i],nums[j],nums[k]});
//                 }
//             }
//          }
//        }
//        return result;
//    }

    // 第二次提交，直接去除nums 数组中的重复元素也会导致结果遗漏
//    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
//
//
//        // 第一步，去除nums 中重复的元素
//        std::sort(nums.begin(), nums.end()); // 排序
//        auto newEnd = std::unique(nums.begin(), nums.end()); // 移动重复元素至末尾
//        nums.erase(newEnd, nums.end()); // 删除重复元素
//
//        size_t size = nums.size();
//        if(size < 3){
//            return {};
//        }
//        std::vector<std::vector<int>> result;
//        // 通过 for循环的方法锚定两个数
//        for (int i = 0; i < size-2; i++) {
//          for(int j = i+1; j<size -1; j++){
//             int ruler = -(nums[i]+nums[j]);
//             for(int k = j+1; k<size; k++){
//                 if(nums[k] == ruler){
//                     result.push_back({nums[i],nums[j],nums[k]});
//                 }
//             }
//          }
//        }
//        return result;
//    }

    //  第三次提交，超出时间限制（我tm心态崩了
//    bool contains(const std::vector<std::vector<int>>& vec_of_vecs, const std::vector<int>& vec) {
//        // 对vec进行排序
//        std::vector<int> sorted_vec = vec;
//        std::sort(sorted_vec.begin(), sorted_vec.end());
//
//        // 遍历vec_of_vecs并检查是否存在sorted_vec
//        for (const auto& existing_vec : vec_of_vecs) {
//            std::vector<int> sorted_existing_vec = existing_vec;
//            std::sort(sorted_existing_vec.begin(), sorted_existing_vec.end());
//            if (sorted_existing_vec == sorted_vec) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
//        size_t size = nums.size();
//
//        std::vector<std::vector<int>> result;
//        // 通过 for循环的方法锚定两个数
//        for (int i = 0; i < size - 2; i++) {
//            for (int j = i + 1; j < size - 1; j++) {
//                int ruler = -(nums[i] + nums[j]);
//                for (int k = j + 1; k < size; k++) {
//                    if (nums[k] == ruler && !contains(result,{nums[i],nums[j],nums[k]})) {
//                        result.push_back({nums[i], nums[j], nums[k]});
//                    }
//                }
//            }
//        }
//        return result;
//    }

    // 使用双指针法+排序完成这个问题
    // 主要思路就是先排序并锚定一个值，然后将这个值在数组中的下一个值为左指针，数组的最后一个值为右指针
//     std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
//         std::sort(nums.begin(), nums.end()); // 排序
//         std::vector<std::vector<int>> result;
//         int n = nums.size();
//
//         for (int i = 0; i < n - 2; ++i) {
//             // 跳过重复元素，因为这个值已经在之前的一次检测过了
//             if (i > 0 && nums[i] == nums[i - 1]) {
//                 continue;
//             }
//
//             int left = i + 1, right = n - 1;
//             while (left < right) {
//                 int sum = nums[i] + nums[left] + nums[right];
//                 if (sum < 0) {
//                     ++left; // 需要更大的值
//                 } else if (sum > 0) {
//                     --right; // 需要更小的值
//                 } else {
//                     // 找到了一个解
//                     result.push_back({nums[i], nums[left], nums[right]});
//                     // 跳过重复元素
//                     while (left < right && nums[left] == nums[left + 1]) {
//                         ++left;
//                     }
//                     while (left < right && nums[right] == nums[right - 1]) {
//                         --right;
//                     }
//                     ++left;
//                     --right;
//                 }
//             }
//         }
//
//         return result;
//     }

    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        size_t size = nums.size();

        std::vector<std::vector<int>> result;
        for (int i = 0; i < size - 2; i++) {
            // 如果元素重复，跳过
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            const int i_value = nums[i];
            const int *left = &nums[i + 1];
            const int *right = &nums[size - 1];

            while (left < right) {
                const int sum = *left + *right + i_value;
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    result.push_back({i_value, *left, *right});

                    // 去除重复元素，先使用while 循环过渡到两端最后一个重复的元素，两个元素都通过push_back已经加入到结果中
                    // 最后 left++;right--; 取到新的两端元素
                    while (left < right && *left == *(left + 1)) {
                        left++;
                    }
                    while (left < right && *right == *(right - 1)) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

#endif //ALGORITHM_TEST_15_H
