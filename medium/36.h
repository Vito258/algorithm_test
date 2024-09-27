//
// Created by 860122023 on 2024/9/27.
//

#ifndef ALGORITHM_TEST_36_H
#define ALGORITHM_TEST_36_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* 有效的数独 */
class Solution {
public:
    // 以二维数组的方式呈现，同一行不能有相同的数字，同一列能有相同的数字，所在3*3数组不能有相同的数字
    bool isValidSudoku(std::vector<std::vector<char>> &board) {

    }

    // 判断二维数组的子数组中是否有重复数字的方法
    bool isRowRepeat(std::vector<std::vector<char>> line) {

        int row_size = line.size();
        int column_size = line[0].size();

        for (int i = 0; i < column_size; i++) {
            std::sort(line[i].begin(), line[i].end());
            for (int j = 1; j < row_size; i++) {
                if (line[i][j - 1] == line[i][j]) {
                    return false;
                }
            }

        }
        return true;
    }

    // 判断每一列是否有重复数字的方法
//    bool isColumnRepeat(std::vector<std::vector<char>> line) {
//
//        int row_size = line.size();
//        int column_size = line[0].size();
//
//        for (int i = 0; i < row_size; i++) {
//            for (int j = 1; j < column_size; j++) {
//                if (line[j - 1][i] == line[j][i]) {
//                    return false;
//                }
//            }
//        }
//    }

    // 将二维数组反转(列变行，行变列)的方法
    void revVector(std::vector<std::vector<char>> &line) {
        int row_size = line.size();
        int column_size = line[0].size();
    }

    // 将二维数组中的3*3 变为子数组的方法
    void areaVector(std::vector<std::vector<char>> &line){

    }
};

#endif //ALGORITHM_TEST_36_H
