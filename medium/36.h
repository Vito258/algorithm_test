//
// Created by 860122023 on 2024/9/27.
//

#ifndef ALGORITHM_TEST_36_H
#define ALGORITHM_TEST_36_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

/* 有效的数独 */
class Solution {
public:
    // 以二维数组的方式呈现，同一行不能有相同的数字，同一列能有相同的数字，所在3*3数组不能有相同的数字
//    bool isValidSudoku(std::vector<std::vector<char>> &board) {
//        bool flag1  = isRowRepeat(board);
//
//        auto v1 = revVector(board);
//        bool flag2 = isRowRepeat(v1);
//
//        std::vector<std::vector<char>> v2;
//        v2.resize(9, std::vector<char>(9, '.'));
//        splitIntoSubArrays(board,v2);
//
//        bool flag3 = isRowRepeat(v2);
//        return (flag1 && flag2 && flag3);
//    }

    // 判断二维数组的子数组中是否有重复数字的方法(判断每一行是否有重复数字)
    bool isRowRepeat(std::vector<std::vector<char>> line) {

        int row_size = line.size();
        int column_size = line[0].size();

        for (int i = 0; i < column_size; i++) {
            std::sort(line[i].begin(), line[i].end());
            for (int j = 1; j < row_size; j++) {
                if (line[i][j - 1] == line[i][j] && line[i][j - 1] != '.' && line[i][j] != '.') {
                    return false;
                }
            }

        }
        return true;
    }

    // 将二维数组反转(列变行，行变列)的方法
    std::vector<std::vector<char>> revVector(std::vector<std::vector<char>> line) {
        int row_size = line.size();
        int column_size = line[0].size();
        for (int i = 0; i < row_size; i++) {
            for (int j = i + 1; j < column_size; j++) {
                // 进行互换
                std::swap(line[i][j], line[j][i]);
            }
        }
        return line;
    }

    // 定义一个函数来分割9x9数组为9个3x3的子数组
    void splitIntoSubArrays(std::vector<std::vector<char>> &arr, std::vector<std::vector<char>> &subArrays) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // 计算当前元素所在的子数组索引

                // 计算在第几行
                int subArrayIndex = (i / 3) * 3 + (j / 3);
                int subArrayRow = i % 3;
                int subArrayCol = j % 3;

                // 将当前元素添加到对应的子数组中
                subArrays[subArrayIndex][subArrayRow * 3 + subArrayCol] = arr[i][j];
            }
        }
    }

    // 官方题解
    bool isValidSudoku(std::vector<std::vector<char>> &board) {
        int rows[9][9];
        int columns[9][9];
        int subboxes[3][3][9];  // {{{3*3},{3*3},{3*3}},{{3*3},{3*3},{3*3}},{{3*3},{3*3},{3*3}}}

        // 初始化3个数组，每个元素都是0,这3个数组分别代表行，列和3*3 宫
        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subboxes, 0, sizeof(subboxes));

        //
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '0' - 1;

                    // 将值转换为索引
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i / 3][j / 3][index]++;

                    // 大于1就说明有重复的数字
                    if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

};

#endif //ALGORITHM_TEST_36_H
