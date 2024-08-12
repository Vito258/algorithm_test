//
// Created by 860122023 on 2024/8/12.
//

#ifndef ALGORITHM_TEST_6_H
#define ALGORITHM_TEST_6_H

#include <string>
#include <vector>
/* Z 字形变换 */
class Solution {
public:
//    std::string convert(std::string s, int numRows) {
//        if (numRows == 1 || numRows >= s.size()) return s; // 特殊情况处理
//        size_t size = s.size();
//        const char* s_array = s.c_str();
//        const char* result_array;
//        int rows;
//        for(int i=0;i<size;i++){
//           if(rows == 0){
//
//           }else if(rows == numRows -1 ){
//
//           }
//
//           rows++;
//        }
//    }
    std::string convert(std::string s, int numRows) {
        // 特殊情况处理
        if (numRows == 1 || numRows >= s.size()) return s;

        std::vector<std::string> rows(std::min(numRows, int(s.size())));
        // 跟踪当前所在的行
        int curRow = 0;
        // 标记是否向下移动
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            // 变换方向
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        // 得出转换后的结果
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }
        return result;
    }
};

#endif //ALGORITHM_TEST_6_H
