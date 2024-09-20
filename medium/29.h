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
    // 通过穷举的方式查找结果
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
        // rev 记录最终结果是不是负数，两者之间有一个负数时，rev == true
        bool rev = false;
        if (dividend > 0) {
            dividend = -dividend;
            rev = !rev;
        }
        if (divisor > 0) {
            divisor = -divisor;
            rev = !rev;
        }

        // 快速乘算法，用于判断表达式 z * y >= x 是否成立
        // 模拟乘法：
        //   z * y 可以通过逐位累加的方式来模拟。
        //   当 z 的某一位为 1 时，表示 y 应该被累加到 result 中。
        //   当 z 的某一位为 0 时，表示 y 不需要被累加到 result 中。
        auto quickAdd = [](int y, int z, int x) {
            // x 和 y 是负数，z 是正数
            // result表示当前累加的结果, add表示每次累加的值
            int result = 0, add = y;

            // 遍历z的每一位
            while (z) {
                // 判断 z 的二进制表示中最右边的一位（最低位）是否为 1：
                // 为什么最低位为1时才需要累加操作?
                // 乘法的展开：
                //   假设 z 的二进制表示为 b_n b_{n-1} ... b_1 b_0，那么 z * y 可以被表示为 b_n * (2^n * y) + b_{n-1} * (2^{n-1} * y) + ... + b_1 * (2^1 * y) + b_0 * (2^0 * y)。
                //   如果 b_i 为 1，则 2^i * y 需要被加入到结果中。
                //   如果 b_i 为 0，则 2^i * y 不需要被加入到结果中，因为它的值为 0。
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
                // 不能使用除法，这里相当于z/=2,但当z = 1 时，z>>=1 后z == 0
                z >>= 1;
            }
            return true;
        };

        // 在(0,Int_Max] 中通过二分法查找结果
        int left = 1, right = INT_MAX, ans = 0;

        // 当left > right 时，说明已经穷举了所有可能的结果
        while (left <= right) {
            // 注意溢出，并且不能使用除法
            int mid = left + ((right - left) >> 1);
            // check 判断z*x >= y 是否成立
            bool check = quickAdd(divisor, mid, dividend);
            if (check) {
                // 成立
                ans = mid;
                // 注意溢出
                if (mid == INT_MAX) {
                    break;
                }

                // 当前mid 值可能小于结果，需要增大
                left = mid + 1;
            } else {
                // 不成立，因为xy都是负数，所以说明这个mid值大了，需要减小
                right = mid - 1;
            }
        }

        return rev ? -ans : ans;
    }
};

#endif //ALGORITHM_TEST_29_H
