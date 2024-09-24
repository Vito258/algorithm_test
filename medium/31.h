//
// Created by 860122023 on 2024/9/24.
//

#ifndef ALGORITHM_TEST_31_H
#define ALGORITHM_TEST_31_H
#include <vector>
#include <iostream>
#include <algorithm>

/* 下一个排列 */
// 必须 原地 修改，只允许使用额外常数空间。
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
class Solution {
public:
    // 尝试自己写,思路如下：
    // 只是找下一个排列不用罗列出所有排列
    // 只要把最后两个nums[n-1]<nums[n],交换一下位置是不是就可以了？
    // 如果n == 1,那么就说明已经是最后一个排列了，直接把nums从小到大升序排列寻找第一个排列

    // 结果报错，只通过了4个测试用例（阿弥诺斯！
    // if(nums[i] < nums[i+1] && (nums[i+1] >= nums[i+2] || i+2 >= size))这行代码越界

//    void nextPermutation(std::vector<int>& nums) {
//        int size = nums.size();
//
//        // 排除特殊情况
//        if(size <= 1){
//           return;
//        }
//
//        if(size == 2){
//
//        }
//        // 遍历数组
//        for(int i=0;i<size-1;++i){
//            // 符合情况，交换值
//            if(nums[i] < nums[i+1] && (nums[i+1] >= nums[i+2] || i+2 >= size)){
//                int temp = nums[i+1];
//                nums[i+1] = nums[i];
//                nums[i] = temp;
//                return;
//            }
//            if(i == size-2){
//                std::sort(nums.begin(),nums.end());
//            }
//        }
//    }

    // 解答错误，[1,3,2]，预期结果[2,1,3] 输出结果[3,1,2],由此可见邻近互换位置这个思路是错误的，但是找到最后nums[n-1]<nums[n]的位置这一点是正确的
//    void nextPermutation(std::vector<int>& nums) {
//        int size = nums.size();
//
//        // 排除特殊情况
//        if(size <= 1){
//            return;
//        }
//
//        if(size == 2){
//
//        }
//        // 遍历数组
//        for(int i=1;i<size;++i){
//            // 符合情况，交换值
//            if(nums[i-1] < nums[i] && (i == size -1 || nums[i] >= nums[i+1] )){
//                int temp = nums[i];
//                nums[i] = nums[i-1];
//                nums[i-1] = temp;
//                return;
//            }
//            if(i == size-1){
//                std::sort(nums.begin(),nums.end());
//                return;
//            }
//
//        }
//    }

    // 官方题解1 ,两遍遍历
    void nextPermutation(std::vector<int>& nums) {
        // 先从倒数第二个数找起，找到最后一组符合nums[n-1]<nums[n]
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 走到这里之时，假如i>=0, 已经说明了nums[i+1] 就是索引为i 之后的最大值，并且是一个递减序列
        // 存在这样一组数，说明当前数列不是最后一种数列
        if (i >= 0) {
            // 从最后一个数向前找起
            int j = nums.size() - 1;

            // 找到一个刚好大于nums[i] 的值并交换
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }
        // 将i 之后的数列按照升序排列，因为其是一个降序序列，所以也就是反转
        reverse(nums.begin() + i + 1, nums.end());
    }
};
#endif //ALGORITHM_TEST_31_H
