# LeetCode 第 165 场周赛

[5275. 找出井字棋的获胜者](https://leetcode-cn.com/problems/find-winner-on-a-tic-tac-toe-game/)

[5276. 不浪费原料的汉堡制作方案](https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients/)

[5277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/)

[5278. 分割回文串 III](https://leetcode-cn.com/problems/palindrome-partitioning-iii/)

C 暴力做的，只能说数据不充分

<!-- more -->

# 找出井字棋的获胜者4

## 题目描述 Description
A 和 B 在一个 3 x 3 的网格上玩井字棋。

井字棋游戏的规则如下：

    玩家轮流将棋子放在空方格 (" ") 上。
    第一个玩家 A 总是用 "X" 作为棋子，而第二个玩家 B 总是用 "O" 作为棋子。
    "X" 和 "O" 只能放在空方格中，而不能放在已经被占用的方格上。
    只要有 3 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。
    如果所有方块都放满棋子（不为空），游戏也会结束。
    游戏结束后，棋子无法再进行任何移动。

给你一个数组 moves，其中每个元素是大小为 2 的另一个数组（元素分别对应网格的行和列），它按照 A 和 B 的行动顺序（先 A 后 B）记录了两人各自的棋子位置。

如果游戏存在获胜者（A 或 B），就返回该游戏的获胜者；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

你可以假设 moves 都 有效（遵循井字棋规则），网格最初是空的，A 将先行动。

## 样例输入与样例输出 Sample Input and Sample Output
示例 1：
```
  输入：moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
  输出："A"
  解释："A" 获胜，他总是先走。
  "X  "    "X  "    "X  "    "X  "    "X  "
  "   " -> "   " -> " X " -> " X " -> " X "
  "   "    "O  "    "O  "    "OO "    "OOX"
```
示例 2：
```
  输入：moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
  输出："B"
  解释："B" 获胜。
  "X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
  "   " -> " O " -> " O " -> " O " -> "XO " -> "XO "
  "   "    "   "    "   "    "   "    "   "    "O  "
```
示例 3：

  输入：moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
  输出："Draw"
  输出：由于没有办法再行动，游戏以平局结束。
  "XXO"
  "OOX"
  "XOX"

示例 4：

输入：moves = [[0,0],[1,1]]
输出："Pending"
解释：游戏还没有结束。
"X  "
" O "
"   "

## 提示 Hint
提示：

    1 <= moves.length <= 9
    moves[i].length == 2
    0 <= moves[i][j] <= 2
    moves 里没有重复的元素。
    moves 遵循井字棋的规则。

## 题解

模拟即可，考虑到 3x3 有看到位运算的做法

## 代码

```c++
class Solution {
 public:

  int run(int g[3][3], vector<int>&move, int val) {
    g[move[0]][move[1]] = val;
    int t = 0, ans = 0;
    for(int i = move[0]; i < 3; ++i) {
      if(g[i][move[1]] == val)
        t++;
      else
        break;
    }
    for(int i = move[0] - 1; i >= 0; --i) {
      if(g[i][move[1]] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    for(int i = move[1]; i < 3; ++i) {
      if(g[move[0]][i] == val)
        t++;
      else
        break;
    }
    for(int i = move[1] - 1; i >= 0; --i) {
      if(g[move[0]][i] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    for(int i = 0; i + move[0] < 3 && i + move[1] < 3; ++i) {
      if(g[i + move[0]][i + move[1]] == val)
        t++;
      else
        break;
    }
    for(int i = -1; i + move[0] >= 0 && i + move[1] >= 0; --i) {
      if(g[i + move[0]][i + move[1]] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    for(int i = 0; i + move[0] < 3 && move[1] - i >= 0; ++i) {
      if(g[i + move[0]][-i + move[1]] == val)
        t++;
      else
        break;
    }
    for(int i = -1; i + move[0] >= 0 && move[1] - i < 3 ; --i) {
      if(g[i + move[0]][-i + move[1]] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    return ans;
  }
  bool finished(int g[3][3]) {
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        if(g[i][j] == 0)
          return false;
    return true;
  }
  string tictactoe(vector<vector<int>>& moves) {
    int g[3][3];
    memset(g, 0, sizeof(g));
    for(int i = 0, n = moves.size(); i < n; ++i) {
      if(run(g, moves[i], i % 2 + 1) > 2)
        return (i & 1) ?  string("B") : string("A");
    }
    return finished(g) ? string("Draw") : string("Pending");
  }
};

```

# 不浪费原料的汉堡制作方案4

[5276. 不浪费原料的汉堡制作方案](https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients/)

<!-- more -->

## 题目描述 Description
圣诞活动预热开始啦，汉堡店推出了全新的汉堡套餐。为了避免浪费原料，请你帮他们制定合适的制作计划。

给你两个整数 tomatoSlices 和 cheeseSlices，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：

    巨无霸汉堡：4 片番茄和 1 片奶酪
    小皇堡：2 片番茄和 1 片奶酪

请你以 [total_jumbo, total_small]（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，使得剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量都是 0。

如果无法使剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量为 0，就请返回 []。

## 样例输入与样例输出 Sample Input and Sample Output
示例 1：

输入：tomatoSlices = 16, cheeseSlices = 7
输出：[1,6]
解释：制作 1 个巨无霸汉堡和 6 个小皇堡需要 4*1 + 2*6 = 16 片番茄和 1 + 6 = 7 片奶酪。不会剩下原料。

示例 2：

输入：tomatoSlices = 17, cheeseSlices = 4
输出：[]
解释：只制作小皇堡和巨无霸汉堡无法用光全部原料。

示例 3：

输入：tomatoSlices = 4, cheeseSlices = 17
输出：[]
解释：制作 1 个巨无霸汉堡会剩下 16 片奶酪，制作 2 个小皇堡会剩下 15 片奶酪。

示例 4：

输入：tomatoSlices = 0, cheeseSlices = 0
输出：[0,0]

示例 5：

输入：tomatoSlices = 2, cheeseSlices = 1
输出：[0,1]

## 提示 Hint
提示：

    0 <= tomatoSlices <= 10^7
    0 <= cheeseSlices <= 10^7

## 题解
先考虑全部用作小皇堡，剩下的每 2 片番茄将一个小皇堡换成巨无霸汉堡。注意边界和特判。
## 代码
```c++
class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if(tomatoSlices > cheeseSlices * 4)
      return vector<int> {};
    vector<int> ans(2);
    ans[1] = cheeseSlices;
    tomatoSlices -= 2 * cheeseSlices;
    if(tomatoSlices < 0 || (tomatoSlices & 1))
      return vector<int> {};
    ans[1] -= tomatoSlices / 2;
    ans[0] += tomatoSlices / 2;
    tomatoSlices -= tomatoSlices - (tomatoSlices & 1);
    if(tomatoSlices != 0)
      return vector<int> {};
    return ans;
  }
};

```

# 统计全为 1 的正方形子矩阵5

[5277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/)

<!-- more -->

## 题目描述 Description

给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

## 样例输入与样例输出 Sample Input and Sample Output
示例 1：

  输入：matrix =
  [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
  ]
  输出：15
  解释：
  边长为 1 的正方形有 10 个。
  边长为 2 的正方形有 4 个。
  边长为 3 的正方形有 1 个。
  正方形的总数 = 10 + 4 + 1 = 15.

示例 2：

  输入：matrix =
  [
    [1,0,1],
    [1,1,0],
    [1,1,0]
  ]
  输出：7
  解释：
  边长为 1 的正方形有 6 个。
  边长为 2 的正方形有 1 个。
  正方形的总数 = 6 + 1 = 7.

## 提示 Hint

  1 <= arr.length <= 300
  1 <= arr[0].length <= 300
  0 <= arr[i][j] <= 1

## 题解

暴力可过，显然数据强度不够。

## 代码

```c++
class Solution {
 public:
  int n, m;
  int countSquares(vector<vector<int>>& matrix) {
    n = matrix.size(), m = matrix[0].size();
    int ans(0);
    for(int i = 1, c; i <= min(n, m); ++i) {
      c = count(matrix, i);
      ans += c;
      if(!c)
        break;
    }
    return ans;
  }
  int count(vector<vector<int> >&matrix, int edgeLen) {
    int ans(0);
    for(int i = 0; i < n - edgeLen + 1; ++i) {
      for(int j = 0; j < m - edgeLen + 1; ++j)
        if(isSquareAllOne(matrix, i, j, edgeLen))
          ans++;
    }
    return ans;
  }

  bool isSquareAllOne(vector<vector<int>>&matrix, int x, int y, int edgeLen) {
    for(int i = 0; i < edgeLen; ++i) {
      for(int j = 0; j < edgeLen; ++j)
        if(!matrix[x + i][y + j])
          return false;
    }
    return true;
  }
};
```
# 分割回文串 III

[5278. 分割回文串 III](https://leetcode-cn.com/problems/palindrome-partitioning-iii/)
<!-- more -->

## 题目描述 Description
给你一个由小写字母组成的字符串 s，和一个整数 k。

请你按下面的要求分割字符串：

    首先，你可以将 s 中的部分字符修改为其他的小写英文字母。
    接着，你需要把 s 分割成 k 个非空且不相交的子串，并且每个子串都是回文串。

请返回以这种方式分割字符串所需修改的最少字符数。

## 样例输入与样例输出 Sample Input and Sample Output
示例 1：

输入：s = "abc", k = 2
输出：1
解释：你可以把字符串分割成 "ab" 和 "c"，并修改 "ab" 中的 1 个字符，将它变成回文串。

示例 2：

输入：s = "aabbc", k = 3
输出：0
解释：你可以把字符串分割成 "aa"、"bb" 和 "c"，它们都是回文串。

示例 3：

输入：s = "leetcode", k = 8
输出：0

## 提示 Hint

    1 <= k <= s.length <= 100
    s 中只含有小写英文字母。

## 题解
dp[i][j] 表示以 i 结尾，分成 j 段的最少修改次数。枚举上一段结尾的位置 pre，`dp[i][j] = min(dp[i][j],dp[pre][j-1]) `

## 代码
```c++
class Solution {
 public:
  int palindromePartition(string s, int k) {
    int dp[s.length()][k + 1];
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < s.length(); ++i) { // end with s[i]
      for(int j = 1; j <= k && j <= i + 1; ++j) { // has j segments
        if(j == 1)
          dp[i][j] = transferCost(s, 0, i);
        else
          for(int pre = max(j - 2, 0); pre < i; ++pre) {
            dp[i][j] = min(dp[i][j], dp[pre][j - 1] + transferCost(s, pre + 1, i));
          }
      }
    }
    return dp[s.length() - 1][k];
  }
  int transferCost(string s, int l, int r) {
    int ans(0);
    for(int i = 0; i < (r - l + 1) / 2; ++i)
      if(s[i + l] != s[r - i])
        ans++;
    return ans;
  }
};

```
