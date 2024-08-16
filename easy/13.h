//
// Created by 860122023 on 2024/8/16.
//

#ifndef ALGORITHM_TEST_13_H
#define ALGORITHM_TEST_13_H

#include <string>
#include <iostream>
#include <vector>
class Solution {
public:
    int romanToInt(std::string s) {
        const std::vector<std::pair<std::string, int>> romanSymbols = {
                {"M",1000}, {"CM",900}, { "D",500}, {"CD",400},
                {"C",100}, {"XC",90}, {"L",50}, {"XL",40},
                {"X",10}, {"IX",9}, {"V",5}, {"IV",4}, {"I",1}
        };
        int result = 0;
        for(const auto& symbol:romanSymbols){
            while(std::mismatch(symbol.first.begin(), symbol.first.end(), s.begin()).first == symbol.first.end())
            {
                result += symbol.second;
                s.erase(0, symbol.first.length());
            }
        }
        return result;
    }
};
#endif //ALGORITHM_TEST_13_H
