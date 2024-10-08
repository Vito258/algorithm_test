//
// Created by 860122023 on 2024/9/3.
//

#ifndef ALGORITHM_TEST_TEST_H
#define ALGORITHM_TEST_TEST_H

//#include "../hard/23.h"
#include <algorithm>
#include "../hard/25.h"
#include "../easy/26.h"

class Test {
    // 23. 分而治之
    // 合并两个链表的方法
//    ListNode *mergeTwoListNode(ListNode *a, ListNode *b) {
//        if (a == nullptr || b == nullptr)
//            return a ? a : b;
//        ListNode *head = new ListNode(0, nullptr);
//        ListNode *tail = head;
//        ListNode *aPtr = a;
//        ListNode *bPtr = b;
//        while (aPtr && bPtr) {
//            if (aPtr->val < bPtr->val) {
//                tail->next = aPtr;
//                aPtr = aPtr->next;
//            } else {
//                tail->next = bPtr;
//                bPtr = bPtr->next;
//            }
//            tail = tail->next;
//        }
//
//        tail->next = (aPtr ? aPtr : bPtr);
//        return head->next;
//    }
//
//    ListNode *merge(std::vector<ListNode *> lists, int l, int r) {
//        if (l == r) {
//            return lists[r];
//        } else if (l > r) {
//            return nullptr;
//        }
//
//        int mid = (r + l) >> 1;
//
//        return mergeTwoListNode(merge(lists, l, mid), merge(lists, mid + 1, r));
//    }
//
//
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        return merge(lists, 0, lists.size() - 1);
//    }


    //23. 使用优先队列
//    struct Status {
//        int val;
//        ListNode *node;
//
//        bool operator<(const Status &rhs) const {
//            return val > rhs.val;
//        }
//    };
//
//    std::priority_queue<Status> p;
//
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        ListNode *head = new ListNode(0, nullptr);
//        ListNode *tail = head;
//
//        for (ListNode *a: lists) {
//            if (a) p.push({a->val, a});
//        }
//
//        while (!p.empty()) {
//            auto f = p.top();
//            p.pop();
//            tail->next = f.node;
//            tail = tail->next;
//            if (f.node -> next)
//                p.push({f.node ->next->val,f.node ->next});
//        }
//        return head->next;
//    }

    // 使用Status 是不是有点丑陋？
    // 1、直接在优先队列里面储存ListNode，并改写ListNode 的 < 运算符  这样做不对，还是需要在ListNode中定义friend 函数才能在外面改动
    // 2、直接给优先队列 自定义比较器
//    struct CompareListNode {
//        bool operator()(const ListNode* lhs, const ListNode* rhs) const {
//            return lhs->val > rhs->val; // 按照从小到大的顺序
//        }
//    };
//
//    // 使用 std::priority_queue，并指定三个模板参数：
//    // 第一个参数是队列中存储的对象类型 ListNode。
//    // 第二个参数是底层容器类型，默认为 std::vector<ListNode>。
//    // 第三个参数是自定义比较器类型 CompareListNode。
//    std::priority_queue<ListNode *, std::vector<ListNode*>, CompareListNode> q;
//
//    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//      for(auto a: lists){
//          if(a) q.push(a);
//      }
//
//      ListNode *dummy = new ListNode(0, nullptr);
//      ListNode *tail = dummy;
//      while(!q.empty()){
//          ListNode* f = q.top();q.pop();
//          tail->next = f;
//          tail = tail ->next;
//          if(f -> next) q.push(f->next);
//      }
//        return dummy ->next;
//    }

    // 24.两两交换链表中的结点
//     ListNode *swapPairs(ListNode *head) {
//        ListNode *dummy = new ListNode(0, head);
//        ListNode *prev = dummy;
//        ListNode *curr = dummy -> next;
//
//        while(curr && curr ->next){
//            ListNode *next = curr ->next;
//            next -> next = curr;
//            ListNode *nextPair = curr ->next ->next;
//            curr ->next = nextPair;
//
//            prev ->next = next;
//            prev = curr;
//            curr = nextPair;
//        }
//         return dummy ->next;
//     }

    // 使用递归的写法
//    ListNode *swapPairs(ListNode *head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        ListNode *headNext = head->next;
//
//        ListNode *pair = swapPairs(headNext->next);
//        headNext->next = head;
//        head -> next = pair;
//        return headNext;
//    }

    // 25、反转k个链表
    std::pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *endNode) {
        ListNode *prev = endNode->next;
        ListNode *current = head;
        while (prev != endNode) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return {endNode, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *prevNode = dummy;
        ListNode *endNode = dummy;

        while (head) {
            for (int i = 0; i < k; ++i) {
                endNode = endNode->next;
                if (endNode == nullptr) {
                    return dummy->next;
                }
            }

            // 保存下一组的第一个节点
            ListNode *nextGroup = endNode->next;
            std::tie(head, endNode) = myReverse(head, endNode);
            prevNode->next = head;
            endNode->next = nextGroup;
            prevNode = endNode;
            head = nextGroup;
        }

        delete dummy;  // 释放 dummy 节点的内存
        return dummy->next;
    }

    // 26.删除数组中的重复元素，使用双指针的方法
    // 大体思路就是一个指针向前读值，另一个指针用于在后面作比较
    int removeDuplicates(std::vector<int> &nums) {
        size_t size = nums.size();
        if (size == 0)
            return 0;
        int fast = 1;
        int slow = 1;
        while (fast < size) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }

    // 27、删除数组中指定的元素 双指针优化法
    int removeElement(std::vector<int> &nums, int val) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }

    // 28、匹配字符串
//    int strStr(std::string s, std::string p) {
//        int s_size = s.size();
//        int p_size = p.size();
//        for(int i = 0; i<= s_size - p_size; i++){
//            int j = i;
//            int k = 0;
//
//            while(k < p_size && s[j] == p[k]){
//                j++;
//                k++;
//            }
//            if(k == p_size) return i;
//        }
//        return -1;
//    }
    // 28、使用Kmp算法匹配
    int strStr(std::string s, std::string p) {
        size_t s_size = s.size();
        size_t p_size = p.size();

        if (p_size > s_size) {
            return -1;
        }
        if (s_size == 0) {
            return -1;
        }
        std::vector<int> next(p_size, 0);

        int j = 0;
        for (int i = 1; i < p_size; i++) {
            while (j > 0 && p[i] != p[j]) {
                j = next[j - 1];
            }
            if (p[i] == p[j]) {
                j++;
            }
            next[i] = j;
        }
        j = 0;
        for (int i = 0; i < s_size; i++) {
            while (j > 0 && s[i] != p[j]) {
                j = next[j - 1];
            }
            if (s[i] == p[j]) {
                j++;
            }
            if (j == p_size) {
                return i - p_size + 1;
            }
        }
        return -1;
    }

    // 29、二分法实现除法
    int divide(int dividend, int divisor) {
        //排除特殊情况
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            } else if (divisor == 1) {
                return INT_MIN;
            }
        }
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }

        if (divisor == 0) {
            return 0;
        }

        // 记录结果符号
        bool isNegative = false;
        if (dividend > 0) {
            dividend = -dividend;
            isNegative = !isNegative;
        }

        if (divisor > 0) {
            divisor = -divisor;
            isNegative = !isNegative;
        }

        // 快速乘算法
        // a : 被除数  < 0
        // b : 除数    < 0
        // c : 中间值   > 0
        // 用于判断 b*c >= a 是不是成立
        auto quickAdd = [](int a, int b, int c) {
            int result = 0, add = b;
            while (c) {
                if (c & 1) {
                    if (result < a - add) return false;
                    result += add;
                }
                if (c != 1) {
                    if (add < a - add) return false;
                    add += add;
                }
                c >>= 1;
            }
            return true;
        };

        int left = 0, right = INT_MAX, ans = 0;
        while (left <= right) {
            int middle = (left + right) >> 1;
            bool check = quickAdd(dividend, divisor, middle);
            if (check) {
                ans = middle;
                if (middle == INT_MAX) break;   // 防止溢出
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return isNegative ? -ans : ans;
    }

    // 31、两遍遍历法寻找下一个序列
    void nextPermutation(std::vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }
        std::sort(nums.begin() + i + 1, nums.end());
    }

    // 39、搜索回溯找组合和
    void dfs(std::vector<int> &candinate, int target, int index, std::vector<int> combine,
             std::vector<std::vector<int>> &ans) {
        if (index = candinate.size()) {
            return;
        }
        if (target = 0) {
            ans.emplace_back(combine);
            return;
        }
        dfs(candinate, target, index + 1, combine, ans);

        if (target - candinate[index]) {
            combine.emplace_back(target);
            dfs(candinate, target - candinate[index], index, combine, ans);
            combine.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> combine;
        dfs(candidates, target, 0, combine, ans);
        return ans;
    }

    // 43、字符串相乘
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size();
        int n2 = num2.size();

        // 初始化结果数组
        std::vector<int> result;
        result.resize(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; ++i) {
            int n1_last = num1[i] - '0';
            int carry = 0;
            for (int j = n2 - 1; j >= 0; ++j) {
                int n2_last = num2[j] - '0';
                int sum = n1_last * n2_last + result[i + j + 1] + carry;
                result[i + j + 1] = sum % 10;
                carry = sum / 10;
            }
            result[i] += carry;
        }

        std::string result_string;
        bool leading_zero = true;
        for (int digt: result) {
            if (leading_zero && digt == 0)
                continue;
            leading_zero = false;
            result_string.push_back(digt + '0');
        }
        if (result_string.empty()) {
            return "0";
        }
        return result_string;
    }

    //
    int jump(std::vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) {
            return 1;
        }
        int maxReach = 0;
        int end = 0;
        int step = 0;
        for (int i = 0; i < n - 1; ++i) {
            maxReach = std::max(maxReach, i + nums[i]);
            if (i == end) {
                step++;
                end = maxReach;
            }
            if(end >= n-1) break;
        }
        return step;
    }
};

#endif //ALGORITHM_TEST_TEST_H
