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
    // 第一种想法，按照索引删除，这种方法不对，当删除了一个元素后，nums数组的索引就会发生变化
//    int removeDuplicates(std::vector<int> &nums) {
//        size_t size = nums.size();
//        if (size < 2){
//            return size;
//        }
//        int elementRem = 105;
//        for(int i=0;i<size; i++){
//            if(nums[i] == elementRem){
//                nums.erase(nums.begin() + i);
//            }else {
//                elementRem = nums[i];
//            }
//        }
//        for(int num :nums){
//            std::cout<<num<<std::endl;
//        }
//        return nums.size();
//    }

    // 通过使用的是遍历的方法，效率太低了
//    int removeDuplicates(std::vector<int> &nums) {
//        size_t size = nums.size();
//        if (size < 2){
//            return size;
//        }
//        int elementRem = 105;
//
//        int count = 0;
//        for(int i=0;i<size; i++){
//            if(nums[count] == elementRem){
//                nums.erase(nums.begin() + count);
//            }else {
//                elementRem = nums[count];
//                count++;
//            }
//        }
//        for(int num :nums){
//            std::cout<<num<<std::endl;
//        }
//        return nums.size();
//    }

    // 使用双指针的方法进行优化，官方题解
    // 大体思路就是一个指针向前读值，另一个指针用于赋值，把重复的值盖掉，这哪里是删除了啊喂！
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

#endif //ALGORITHM_TEST_26_H
