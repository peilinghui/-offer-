class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (numbers[mid] <= numbers[r]) r --;
            else l ++;
        }
        return numbers[l];
    }
};
方法2：
class Solution {
public:
    int minArray(vector<int>& numbers) {
        for (int i = 1; i < numbers.size(); i ++) 
            if(numbers[i -1] > numbers[i]) return numbers[i];
        return numbers[0];
    }
};
方法3：
class Solution {
public:
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        return numbers[0];
    }
};







//二分查找
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int> &numbers) {
        int size = numbers.size();
        if (size == 0) {
            return 0;
        }

        int left = 0;
        int right = size - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // int mid = left + ((right - left) >> 1);
            if (numbers[mid] > numbers[right]) {
                // [3, 4, 5, 1, 2]，mid 以及 mid 的左边一定不是最小数字
                // 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1;
            } else if (numbers[mid] == numbers[right]) {
                // 只能把 right 排除掉，下一轮搜索区间是 [left, right - 1]
                right--;
            } else {
                // 此时 numbers[mid] < numbers[right]
                // mid 的右边一定不是最小数字，mid 有可能是，下一轮搜索区间是 [left, mid]
                right = mid;
            }
        }
        return numbers[left];
    }
};

