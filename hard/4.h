//
// Created by 860122023 on 2024/8/8.
//

#ifndef ALGORITHM_TEST_4_H
#define ALGORITHM_TEST_4_H

#include <vector>
#include <algorithm>
/* 寻找两个正序数组的中位数 */
/* 为了达到 O(log (m+n)) 的时间复杂度，我们需要利用二分查找的思想 */
class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        // 对数组进行排序
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(),nums2.end());

        int M = nums1.size();
        int m = M/2;
        int N = nums2.size();
        int n = N/2;

        //分割数组

    }
//    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
//        if (nums1.size() > nums2.size()) {
//            return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller array
//        }
//
//        int x = nums1.size(), y = nums2.size();
//        int low = 0, high = x;
//
//        while (low <= high) {
//            int partitionX = (low + high) / 2;
//            int partitionY = (x + y + 1) / 2 - partitionX;
//
//            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
//            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
//
//            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
//            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
//
//            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
//                if ((x + y) % 2 == 0) {
//                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
//                } else {
//                    return max(maxLeftX, maxLeftY);
//                }
//            } else if (maxLeftX > minRightY) {
//                high = partitionX - 1;
//            } else {
//                low = partitionX + 1;
//            }
//        }
//
//        throw "Input arrays were not sorted";
//    }
};

#endif //ALGORITHM_TEST_4_H
