//
// Created by 111 on 2024/8/29.
//

#ifndef ALGORITHM_TEST_22_H
#define ALGORITHM_TEST_22_H

#include <iostream>
#include <string>
#include <vector>

/* 括号生成 */
// 1 <= n <= 8
class Solution {
public:
    // 尝试自己写：( 然后直接快进到放弃...
//    std::vector<std::string> generateParenthesis(int n) {
//        // 先处理特殊情况
//        if (n == 1) {
//            return {"()"};
//        }
//
//        // 字符串内容但从 "("来看，索引0 肯定是"("，末尾肯定是")",而中间各种排列组合的种类数就是result 数组的元素数
//        // 字符串长度为2*n
//        size_t size = 2 * n;
//
//        // 在[1,2n-2] 之间，寻找(n-1) 个数的排列组合  -- 这种想法不对，pass！！！
//
//    }

    // 官方题解1 - 暴力法
    // 判断是否有效
    bool valid(const std::string& str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    // 回溯的方式遍历每一种可能
    void generate_all(std::string& current, int n, std::vector<std::string>& result) {
        // n == current.size 说明已经成为了一个完整的字符串
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }

        // 核心代码
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }

//    std::vector<std::string> generateParenthesis(int n) {
//        std::vector<std::string> result;
//        std::string current;
//        generate_all(current, n * 2, result);
//        return result;
//    }


    // 剪枝，本质还是回溯,个人觉得最简洁最好理解的一版
//    std::vector<std::string> generateParenthesis(int n) {
//        dfs("", n, n);
//        return res;
//    }
//private:
//    std::vector<std::string> res;
//    void dfs(const std::string& str, int left, int right) {
//        // 这里的判断的意义在于看是不是左括号太多或者右括号太多，不是有意义的状态，直接返回
//        if (left < 0 || left > right)  // 出现类似 ()) )) 这种格式都是错误的不用再继续了
//            return;
//        if (left == 0 && right == 0) {
//            res.push_back(str);
//            return;
//        }
//        //
//        dfs(str + '(', left - 1, right);
//        dfs(str + ')', left, right - 1);
//    }

    std::vector<std::string> generateParenthesis(int n) {
       dfs("",n,n);
        return res;
    }
    void dfs(std::string str,int left, int right){
      if(left < 0 || left > right){
          return;
      }else if (left == 0 && right == 0){
          res.push_back(str);
          return;
      }
        dfs(str+"(",left - 1,right);
        dfs(str+")",left,right - 1);
    }
private:
    std::vector<std::string> res;
};

#endif //ALGORITHM_TEST_22_H
