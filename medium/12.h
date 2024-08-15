//
// Created by 860122023 on 2024/8/15.
//

#ifndef ALGORITHM_TEST_12_H
#define ALGORITHM_TEST_12_H

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
/* 整数转罗马数字
 * 1 <= num <= 3999
 * */

class Solution {
public:

    // 自己尝试写，果然是拆了东墙补西墙的屎山,但是好歹过了
//    std::string intToRoman(int num) {
//        // 基础的字符
//        std::string one = "I";
//        std::string five = "V";
//        std::string ten = "X";
//        std::string fifty = "L";
//        std::string hundred = "C";
//        std::string fiveHundred = "D";
//        std::string thousand = "M";
//
//        //  对 10 的位数计数
//        int times = 0;
//        int num_copy = num;
//        while ((num_copy / 10) != 0){
//            times++;
//            num_copy /= 10;
//        }
//
//        std::string result;
//        for(int i = times; i >= 0; i--){
//            int ten_power = pow(10,i);
//            int temp =  num / ten_power;  // 当前位的值，从高位向低位计算,temp 的值永远属于 [1,9]
//            if(temp == 0){
//                continue;
//            }
//            // 标尺
//            std::string ruler;
//
//            // [1000， 3999]
//            if(i >= 3){
//                ruler = thousand;
//                if(temp > 1)
//                   ruler += std::string(temp - 1, thousand[0]);
//            }
//            // [500，1000）
//            else if(i == 2 && temp >= 5){
//                if(temp == 9){
//                    ruler = thousand;
//                    ruler.insert(0,hundred);
//                }else{
//                    ruler = fiveHundred;
//                    ruler += std::string(temp - 5, hundred[0]);
//                }
//            }
//            // [100,500)
//            else if(i == 2){
//                if(temp == 4){
//                    ruler = fiveHundred;
//                    ruler.insert(0,hundred);
//                }else{
//                    ruler = hundred;
//                    if(temp > 1)
//                      ruler += std::string(temp - 1, hundred[0]);
//                }
//            }
//            // [50,100)
//            else if(i == 1 && temp >= 5){
//                if(temp == 9){
//                    ruler = hundred;
//                    ruler.insert(0,ten);
//                }else{
//                    ruler = fifty;
//                    ruler += std::string(temp - 5, ten[0]);
//                }
//            }
//            // [10,50)
//            else if(i == 1){
//                if(temp == 4){
//                    ruler = fifty;
//                    ruler.insert(0,ten);
//                }else{
//                    ruler = ten;
//                    if(temp >1)
//                     ruler += std::string(temp -1, ten[0]);
//                }
//            }
//            // [5,10)
//            else if(temp >= 5){
//                if(temp == 9){
//                    ruler = ten;
//                    ruler.insert(0,one);
//                }else{
//                    ruler = five;
//                    ruler += std::string(temp - 5,one[0]);
//                }
//            }
//            // [1,5)
//            else{
//                if(temp == 4){
//                    ruler = five;
//                    ruler.insert(0,one);
//                }else{
//                    ruler = one;
//                    if(temp > 1)
//                       ruler += std::string(temp - 1,one[0]);
//                }
//            }
//            num %= ten_power;
//            result.append(ruler);
//        }
//        return result;
//    }

    // 将特殊表示使用vector储存
    std::string intToRoman(int num) {
        const std::vector<std::pair<int, std::string>> romanSymbols = {
                {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        std::string result;
        for (const auto& symbol : romanSymbols) {
            while (num >= symbol.first) {
                result += symbol.second;
                num -= symbol.first;
            }
        }
        return result;
    }
};
#endif //ALGORITHM_TEST_12_H
