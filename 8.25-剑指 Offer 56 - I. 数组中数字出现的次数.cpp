剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

 

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n : nums) res ^= n;
        int a = 0, b = 0;
        int mask = 1;
        while ((mask & res) == 0) mask <<= 1;
        for (int n : nums) {
            if (n & mask)
                a ^= n;
            else
                b ^= n;
        }
        return {a, b};
    }
};
