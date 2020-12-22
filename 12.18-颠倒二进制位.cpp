190. 颠倒二进制位
颠倒给定的 32 位无符号整数的二进制位。

 

示例 1：

输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
示例 2：

输入：11111111111111111111111111111101
输出：10111111111111111111111111111111
解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
     因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。



类似十进制翻转，只是每一次循环加的数字只能为1或0
//res不断左移，n不断右移，共计32次。
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res = (res << 1) + (n & 1);
            n >>= 1;
        }
        return res;
    }
};

移动最后一位到第一位（4 行代码，O(1) 时间复杂度）

解题思路
取当前 n 的最后一位：n & 1
将最后一位移动到对应位置，第一次为 31 位，第二次是 30 位，即：31、30、29... 1、0，写作代码 bit << 31;
退出条件，二进制反转时，如果剩余位数全位 0，则可以不用再反转。
相似练习：
这题的移位操作与以下两题的一致，可同时练习：位 1 的个数、汉明距离。

代码

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ans = 0;
        for (int bitsSize = 31; n != 0; n = n >>> 1, bitsSize--) {
            ans += (n & 1) << bitsSize;
        }
        return ans;
    }
}

class Solution {
public:
    unordered_map<uint32_t, uint32_t> memo;
    uint32_t reverseBits(uint32_t n) {
        if (memo.count(n) > 0)
            return memo[n];
        int res = 0;
        for (int i = 0; i < 32; ++i)
            if (n & (1 << i))
                res |= 1 << (31 - i);
        memo[n] = res;
        return res;
    }
};
