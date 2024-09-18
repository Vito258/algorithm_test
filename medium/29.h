//
// Created by 860122023 on 2024/9/18.
//

#ifndef ALGORITHM_TEST_29_H
#define ALGORITHM_TEST_29_H

#include <iostream>
#include <cstdlib>
/*  29、两数相除  */
//  -2^31 <= dividend, divisor <= 2^31 - 1
//  divisor != 0
class Solution {
public:

    // 尝试自己写（回归原始，使用纯减法
    // 报错：signed integer overflow，
//    int divide(int dividend, int divisor) {
//        bool isNegative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
//
//        int dividend_abs = std::abs(dividend);
//        int divisor_abs = std::abs(divisor);
//
//        int result = -1;
//        // 排除特殊情况
//        // 1、被除数 绝对值小于除数
//        // 2、被除数 为0
//        if (dividend_abs <  divisor_abs || dividend == 0) {
//            return 0;
//        }
//
//        // 循环计算
//        while(dividend_abs >= 0){
//            result++;
//            dividend_abs -= divisor_abs;
//        }
//        if(isNegative){
//            result = -result;
//        }
//        return result;
//    }

    // 对上面代码的优化
    // 还是没有通过，超出时间限制
//    int divide(int dividend, int divisor) {
//        // 处理特殊情况：除数为0
//        if (divisor == 0) {
//            throw std::runtime_error("Divisor cannot be zero.");
//        }
//
//        // 处理特殊情况：被除数为0
//        if (dividend == 0) {
//            return 0;
//        }
//
//        bool isNegative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
//
//        int dividend_abs = std::abs(dividend);
//        int divisor_abs = std::abs(divisor);
//
//        // 处理特殊情况：除数为-2147483648
//        if (divisor_abs == INT_MIN) {
//            if (dividend_abs == INT_MIN) {
//                return 1;
//            } else {
//                return 0;
//            }
//        }
//
//        int result = 0;
//
//        // 循环计算
//        while (dividend_abs >= divisor_abs) {
//            int temp = divisor_abs;
//            int multiple = 1;
//
//            // 加速减法过程
//            while (dividend_abs >= (temp << 1)) {
//                temp <<= 1;
//                multiple <<= 1;
//            }
//
//            // 避免溢出
//            if (dividend_abs - temp < 0) {
//                break;
//            }
//
//            dividend_abs -= temp;
//            result += multiple;
//        }
//
//        if (isNegative) {
//            result = -result;
//        }
//
//        // 检查结果是否越界
//        if (result > INT_MAX) {
//            return INT_MAX;
//        } else if (result < INT_MIN) {
//            return INT_MIN;
//        }
//
//        return result;
//    }

      // 官方题解1 ： 二分查找
      int divide(int dividend, int divisor) {
          // 考虑被除数为最小值的情况
          if (dividend == INT_MIN) {
              if (divisor == 1) {
                  return INT_MIN;
              }
              if (divisor == -1) {
                  return INT_MAX;
              }
          }
          // 考虑除数为最小值的情况
          if (divisor == INT_MIN) {
              return dividend == INT_MIN ? 1 : 0;
          }
          // 考虑被除数为 0 的情况
          if (dividend == 0) {
              return 0;
          }

          // 一般情况，使用二分查找
          // 将所有的正数取相反数，这样就只需要考虑一种情况
          // rev 记录最终结果是不是负数
          bool rev = false;
          if (dividend > 0) {
              dividend = -dividend;
              rev = !rev;
          }
          if (divisor > 0) {
              divisor = -divisor;
              rev = !rev;
          }

          // 快速乘
          auto quickAdd = [](int y, int z, int x) {
              // x 和 y 是负数，z 是正数
              // 需要判断 z * y >= x 是否成立
              int result = 0, add = y;
              while (z) {
                  if (z & 1) {
                      // 需要保证 result + add >= x
                      if (result < x - add) {
                          return false;
                      }
                      result += add;
                  }
                  if (z != 1) {
                      // 需要保证 add + add >= x
                      if (add < x - add) {
                          return false;
                      }
                      add += add;
                  }
                  // 不能使用除法
                  z >>= 1;
              }
              return true;
          };

          int left = 1, right = INT_MAX, ans = 0;
          while (left <= right) {
              // 注意溢出，并且不能使用除法
              int mid = left + ((right - left) >> 1);
              bool check = quickAdd(divisor, mid, dividend);
              if (check) {
                  ans = mid;
                  // 注意溢出
                  if (mid == INT_MAX) {
                      break;
                  }
                  left = mid + 1;
              }
              else {
                  right = mid - 1;
              }
          }

          return rev ? -ans : ans;
      }
};

#endif //ALGORITHM_TEST_29_H
