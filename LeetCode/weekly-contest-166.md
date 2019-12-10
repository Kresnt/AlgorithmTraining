# LeetCode-第 166 场周赛
[1281.subtract-the-product-and-sum-of-digits-of-an-integer](https://leetcode-cn.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)

[1282.group-the-people-given-the-group-size-they-belong-to](https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to/)

[1283.find-the-smallest-divisor-given-a-threshold](https://leetcode-cn.com/problems/find-the-smallest-divisor-given-a-threshold/)

[1284.minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix](https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)


# 1281.整数的各位积和之差

[1281.subtract-the-product-and-sum-of-digits-of-an-integer](https://leetcode-cn.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)

<!-- more -->

## 题目描述 Description
给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。


## 样例输入与样例输出 Sample Input and Sample Output
示例 1：
```
输入：n = 234
输出：15 
解释：
各位数之积 = 2 * 3 * 4 = 24 
各位数之和 = 2 + 3 + 4 = 9 
结果 = 24 - 9 = 15
```
示例 2：
```
输入：n = 4421
输出：21
解释： 
各位数之积 = 4 * 4 * 2 * 1 = 32 
各位数之和 = 4 + 4 + 2 + 1 = 11 
结果 = 32 - 11 = 21
```
## 提示 Hint
1 <= n <= 10^5

## 代码
```c++
class Solution {
 public:
  int p(int n) {
    int ans(1);
    while(n)
      ans *= n % 10, n /= 10;
    return ans;
  }
  int s(int n) {
    int ans(0);
    while(n)
      ans += n % 10, n /= 10;
    return ans;
  }

  int subtractProductAndSum(int n) {
    return p(n) - s(n);
  }
};

```

# 1282.用户分组

[1282.group-the-people-given-the-group-size-they-belong-to](https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to/)

<!-- more -->

## 题目描述 Description
有 n 位用户参加活动，他们的 ID 从 0 到 n - 1，每位用户都 恰好 属于某一用户组。给你一个长度为 n 的数组 groupSizes，其中包含每位用户所处的用户组的大小，请你返回用户分组情况（存在的用户组以及每个组中用户的 ID）。

你可以任何顺序返回解决方案，ID 的顺序也不受限制。此外，题目给出的数据保证至少存在一种解决方案。


## 样例输入与样例输出 Sample Input and Sample Output
示例 1：
```
输入：groupSizes = [3,3,3,3,3,1,3]
输出：[[5],[0,1,2],[3,4,6]]
解释： 
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
```
示例 2：
```
输入：groupSizes = [2,1,3,3,3,2]
输出：[[1],[0,5],[2,3,4]]
```
## 提示 Hint
```
    groupSizes.length == n
    1 <= n <= 500
    1 <= groupSizes[i] <= n
```

## 代码
```c++
using std::vector;
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int n = groupSizes.size();
    vector<vector<int>> ans;
    vector<int> g[n + 1];
    for(int i = 0; i < n; ++i) {
      g[groupSizes[i]].push_back(i);
      if(g[groupSizes[i]].size() == groupSizes[i]) {
        ans.push_back(g[groupSizes[i]]);
        g[groupSizes[i]].clear();
      }
    }
    return ans;
  }
};

```
# 1283.使结果不超过阈值的最小除数

[1283.find-the-smallest-divisor-given-a-threshold](https://leetcode-cn.com/problems/find-the-smallest-divisor-given-a-threshold/)

<!-- more -->

## 题目描述 Description
给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。

请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。

每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。

题目保证一定有解。


## 样例输入与样例输出 Sample Input and Sample Output
示例 1：
```
输入：nums = [1,2,5,9], threshold = 6
输出：5
解释：如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
```
示例 2：
```
输入：nums = [2,3,5,7,11], threshold = 11
输出：3
```
示例 3：
```
输入：nums = [19], threshold = 5
输出：4
```
## 提示 Hint
1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6


## 代码
```c++
class Solution {
 public:
  int cal(vector<int>&nums, int x) {
    int ans(0);
    for(auto i : nums) {
      ans += (i+x-1) / x;
    }
    return ans;
  }
  int smallestDivisor(vector<int>& nums, int threshold) {
    int first = 1, middle, half, len = *max_element(nums.begin(), nums.end());
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      if(cal(nums, middle) > threshold) {
        first = middle + 1;
        len = len - half - 1;
      } else
        len = half;
    }
    return first;
  }

};

```

# 1284.转化为全零矩阵的最少反转次数

[1284.minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix](https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)

<!-- more -->

## 题目描述 Description
给你一个 m x n 的二进制矩阵 mat。

每一步，你可以选择一个单元格并将它反转（反转表示 0 变 1 ，1 变 0 ）。如果存在和它相邻的单元格，那么这些相邻的单元格也会被反转。（注：相邻的两个单元格共享同一条边。）

请你返回将矩阵 mat 转化为全零矩阵的最少反转次数，如果无法转化为全零矩阵，请返回 -1 。

二进制矩阵的每一个格子要么是 0 要么是 1 。

全零矩阵是所有格子都为 0 的矩阵。


## 样例输入与样例输出 Sample Input and Sample Output
示例 1：
```
输入：mat = [[0,0],[0,1]]
输出：3
解释：一个可能的解是反转 (1, 0)，然后 (0, 1) ，最后是 (1, 1) 。
```
示例 2：
```
输入：mat = [[0]]
输出：0
解释：给出的矩阵是全零矩阵，所以你不需要改变它。
```
示例 3：
```
输入：mat = [[1,1,1],[1,0,1],[0,0,0]]
输出：6
```
示例 4：
```
输入：mat = [[1,0,0],[1,0,0]]
输出：-1
解释：该矩阵无法转变成全零矩阵
```
## 提示 Hint
m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] 是 0 或 1 。


## 代码
```c++
#include <bits/stdc++.h>

using std::vector;
using std::min;
class Solution {
 public:
  int digitCount(int x) {
    int ans(0);
    while(x) {
      if(x & 1)
        ans ++;
      x >>= 1;
    }
    return ans;
  }

  inline void flip(int &x) {
    if(x)
      x = 0;
    else
      x = 1;
  }

  int chk(vector<vector<int>>mat, int x) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j) {
        if(x & (1 << i * m + j)) {
          flip(mat[i][j]);
          if(i)
            flip(mat[i - 1][j]);
          if(i < n - 1)
            flip(mat[i + 1][j]);
          if(j)
            flip(mat[i][j - 1]);
          if(j < m - 1)
            flip(mat[i][j + 1]);
        }
      }
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        if(mat[i][j])
          return false;
    return true;
  }

  int minFlips(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    const int inf = 0x3f3f3f3f;
    int ans(inf);
    for(int i = 0; i < (1 << n * m); ++i)
      if(chk(mat, i))
        ans = min(ans, digitCount(i));
    return ans == inf ? -1 : ans;
  }

};

```