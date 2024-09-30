//
// Created by 860122023 on 2024/8/7.
//
#include "40.h"
#include "../utils/utils.h"

int main() {
    //10的测试用例
//    std::string s1 = "aa";
//    std::string s2 = "a";
//    std::string s3 = "a*";
//    std::string s4 = "ab";
//    std::string s5 = ".*";
//    std::string s6 = "mississippi";
//    std::string s7 = "mis*is*p*.";     //预期结果是false
//    std::string s8 = "mis*is*ip*.";    //预期结果是true
//    Solution solution;
//    std::cout<< solution.isMatch(s6,s7);

//      Solution solution;
//      std::vector<std::vector<char>> board1 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
//      std::vector<std::vector<char>> board2 = {{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}};
//      std::cout<< solution.isValidSudoku(board2);

        Solution solution;
        std::vector<int> v1 = {2,5,2,1,2};
        std::vector<std::vector<int>> result =  solution.combinationSum2(v1,5);
        for(int i =0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                std::cout<<result[i][j]<<std::endl;
            }
            std::cout<<"-------------------------"<<std::endl;
        }
}