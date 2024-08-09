//
// Created by 860122023 on 2024/8/8.
//

#ifndef ALGORITHM_TEST_4_H
#define ALGORITHM_TEST_4_H

#include <vector>
#include <algorithm>
#include <ntdef.h>
/* 寻找两个正序数组的中位数 */
/* 为了达到 O(log (m+n)) 的时间复杂度，我们需要利用二分查找的思想 */
class Solution {
public:
//    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
//        // 对数组进行排序
//        std::sort(nums1.begin(), nums1.end());
//        std::sort(nums2.begin(),nums2.end());
//
//        int M = nums1.size();
//        int m = M/2;
//        int N = nums2.size();
//        int n = N/2;
//
//        //分割数组
//
//    }

    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller array
        }

        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x;
        //  首先明确一个事情，中位数总是位于数组分割后的左部分的最右侧或左部分的最右侧和右部分的最左侧之间。
        while (low <= high) {
            // 数组的分割点
            int partitionX = (low + high) / 2;

            // 让左边的元素总数等于 (x + y + 1) / 2，这里加1是为了确保当总元素数为奇数时，中位数位于左侧。
            int partitionY = (x + y + 1) / 2 - partitionX;

            // 最大小于分割点的数
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            // 最小大于分割点的数
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // 如果第一个数组最大小于分割点的数，小于等于第二个数组最小大于分割点的数
            // 并且第二个数组最大小于分割点的数，小于等于第一个数组最小大于分割点的数
            // 说明分割点有效，两个分割数组的左半部分都小于右半部分
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // 如果数组的长度和是偶数
                if ((x + y) % 2 == 0) {
                    return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
                }
                // 如果数组长度的和是奇数
                else {
                    return std::max(maxLeftX, maxLeftY);
                }
            }
            // 如果第一个数组最大小于分割点的数大于第二个数组最小大于分割点的数
            // nums1左侧的最大值大于nums2右侧的最小值，说明partitionX太大，需要减小
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            // 说明nums2左侧的最大值大于nums1右侧的最小值，此时partitionX太小，需要增大
            else {
                low = partitionX + 1;
            }
        }
        throw "Input arrays were not sorted";
    }

//    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
//        int M = nums1.size();
//        int m = M / 2;
//        int N = nums2.size();
//        int n = N / 2;
//
//        //分割数组
//
//    }
};

#endif //ALGORITHM_TEST_4_H
