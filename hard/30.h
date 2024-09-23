//
// Created by 860122023 on 2024/9/23.
//

#ifndef ALGORITHM_TEST_30_H
#define ALGORITHM_TEST_30_H

#include <iostream>
#include <vector>
#include <string>
/* 串联所有单词的字串 */

// 1 <= s.length <= 104
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// words[i] 和 s 由小写英文字母组成
class Solution {
public:
    // 在模板串中找出所有串联字串的开始索引
    // 尝试自己完成：
    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
        int words_size = words.size();
        if(words_size == 0 ){
            return {};
        }
        int word_size = words[0].size();

    }
};

#endif //ALGORITHM_TEST_30_H
