//
// Created by 860122023 on 2024/8/15.
//

#ifndef ALGORITHM_TEST_11_H
#define ALGORITHM_TEST_11_H

/* 盛最多水的容器 */
#include <iostream>
#include <vector>

class Solution {
public:
    // 第一次提交，错误：超出时间限制（话说这是第一次碰见这种力扣的解答错误...
    // 当前的双层循环时间复杂度为 O(n^2)，可以通过“两指针”法优化到 O(n)
//    int maxArea(std::vector<int>& height) {
//      //第i条线的两个端点，(i,0) (i,height[i])
//      //求最大面积
//      size_t height_size =  height.size();
//      size_t height_index = height_size - 1;
//
//      int max_square = 0;
//      for(int i=0; i<height_size; i++){
//          for(int j= height_index; j>i;j--){
//              int square = (j-i) * std::min(height[i],height[j]);
//             if( square > max_square){
//                 max_square = square;
//             }
//          }
//      }
//        return max_square;
//    }

    /*
     * 说一下理解：
     * 首先，width 肯定是越往后执行越小的，而height随着进行起伏不定
     * 假如 left 和right 有一个短板，那么height = 这个短板
     * 随着移动短板, width - 1;而height 一定会升高或保持不变，而控制面积的主要因素就是height
     * 移动短板时，有可能找到一个更高的板，这样可以增加高度，同时宽度虽然减小，但总面积可能增加。
     * 因为每次移动都是从短板开始，所以总能找到一个更好的或者至少同样好的解。
     *
     * 问，为什么这样的方法不会遗漏最大面积？
     * 贪心策略:
             我们总是移动短板，因为这样做可以确保我们不会错过任何可能增加面积的机会。
             如果移动短板导致面积减少，那是因为新的短板高度不足以补偿宽度的减小，但这不会影响我们找到最大面积的能力，因为我们总是有机会找到更高的短板。
             如果移动短板导致面积增加，那么我们找到了一个更好的解。
     * */
    int maxArea(std::vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int max_square = 0;

        while (left < right) {
            int width = right - left;
            int current_area = std::min(height[left], height[right]) * width;

            if (current_area > max_square) {
                max_square = current_area;
            }
            // 移动短板(核心)
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_square;
    }
};

#endif //ALGORITHM_TEST_11_H
