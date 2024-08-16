//
// Created by 860122023 on 2024/8/7.
//
#include "15.h"

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

    Solution solution;
    std::vector<int> nums1 = {-1,0,1,2,-1,-4};
    std::vector<int> nums2 = {0,1,1};
    std::vector<int> nums3 = {0,0,0};

    const auto result = solution.threeSum(nums1);
    for(std::vector<int> v : result){
        for(int i : v)
            std::cout<<i<<",";
        std::cout<<"\n";
    }
}