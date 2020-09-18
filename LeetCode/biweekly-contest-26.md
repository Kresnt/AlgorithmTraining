---
title: LeetCode 第 26 场双周赛
date: 
tag:
  - LeetCode
---

- 5396. 连续字符
- 5397. 最简分数
- 5398. 统计二叉树中好节点的数目
- 5399. 数位成本和为目标值的最大数字

<!-- more -->

## 5396. 连续字符

给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。

示例 1：

输入：s = "leetcode"
输出：2
解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。

示例 2：

输入：s = "abbcccddddeeeeedcba"
输出：5
解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。

示例 3：

输入：s = "triplepillooooow"
输出：5

示例 4：

输入：s = "hooraaaaaaaaaaay"
输出：11

示例 5：

输入：s = "tourist"
输出：1

提示：

    1 <= s.length <= 500
    s 只包含小写英文字母。

-----

```c++
class Solution {
 public:
  int maxPower(string s) {
    int ans(0), c(1);
    if(s.length() == 0)
      return 0;
    ans = 1;
    for(int i = 1, sz = s.length(); i < sz; ++i) {
      if(s[i] == s[i - 1])
        c++;
      else
        c = 1;
      ans = max(ans, c);
    }
    return ans;
  }
};
```

## 5397. 最简分数

给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

示例 1：

输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。

示例 2：

输入：n = 3
输出：["1/2","1/3","2/3"]

示例 3：

输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。

示例 4：

输入：n = 1
输出：[]

提示：

    1 <= n <= 100

---

```c++
class Solution {
 public:
  vector<string> simplifiedFractions(int nn) {
    vector<string>ans;
    for(int n = 2; n <= nn; ++n)
      for(int i = 1; i < n; ++i) {
        if(__gcd(i, n) == 1) {
          //cout<<"hel\n";
          string s = to_string(i) + '/' + to_string(n);
          ans.push_back(s);
        }
      }
    return ans;
  }

};
```

## 5398. 统计二叉树中好节点的数目

给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

示例 1：

输入：root = [3,1,4,3,null,1,5]
输出：4
解释：图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -> (3,4) 是路径中的最大值。
节点 5 -> (3,4,5) 是路径中的最大值。
节点 3 -> (3,1,3) 是路径中的最大值。

示例 2：

输入：root = [3,3,null,4,2]
输出：3
解释：节点 2 -> (3, 3, 2) 不是好节点，因为 "3" 比它大。

示例 3：

输入：root = [1]
输出：1
解释：根节点是好节点。

提示：

    二叉树中节点数目范围是 [1, 10^5] 。
    每个节点权值的范围是 [-10^4, 10^4] 。

---

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int ans;
  int goodNodes(TreeNode* root) {
    ans = 0;
    vector<int>vec;
    DFS(root, vec);
    return ans;
  }

  void DFS(TreeNode * root, vector<int>&vec) {
    if(root == nullptr)
      return ;
    if(vec.size() == 0 ||  root->val >= *max_element(vec.begin(), vec.end())) {
      ans ++;
      cout << root->val << "\n";
    }
    vec.push_back(root->val);
    DFS(root->left, vec);
    DFS(root->right, vec);
    vec.pop_back();
  }
};
```

## 5399. 数位成本和为目标值的最大数字

给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大 整数：

    给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
    总成本必须恰好等于 target 。
    添加的数位中没有数字 0 。

由于答案可能会很大，请你以字符串形式返回。

如果按照上述要求无法得到任何整数，请你返回 "0" 。

示例 1：

输入：cost = [4,3,2,5,6,7,2,5,5], target = 9
输出："7772"
解释：添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772" 的代价为 2*3+ 3*1 = 9 。 "997" 也是满足要求的数字，但 "7772" 是较大的数字。
 数字     成本
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5

示例 2：

输入：cost = [7,6,5,5,5,6,8,7,8], target = 12
输出："85"
解释：添加数位 '8' 的成本是 7 ，添加数位 '5' 的成本是 5 。"85" 的成本为 7 + 5 = 12 。

示例 3：

输入：cost = [2,4,6,2,4,6,4,4,4], target = 5
输出："0"
解释：总成本是 target 的条件下，无法生成任何整数。

示例 4：

输入：cost = [6,10,15,40,40,40,40,40,40], target = 47
输出："32211"

提示：

    cost.length == 9
    1 <= cost[i] <= 5000
    1 <= target <= 5000

---

不要往 NP 问题、带约束的规划最优值问题等方面想，暴力搞就是了。

```c++
class Solution {
 public:
  string largestNumber(vector<int>& cost, int target) {
    vector<string>ans(target + 1);
    ans[0] = "";
    for(int i = 0; i < target; ++i) {
      if(i != 0 && ans[i].length() == 0)
        continue;
      for(int j = 0; j < 9; ++j) {
        if(i + cost[j] > target)
          continue;
        string aa = ans[i] + string(1, (char)('0' + j + 1));
        if(gao_max(aa, ans[i + cost[j]])) {
          ans[i + cost[j]] = aa;
          //cout << i << " " << ans[i] << "update ";
          //cout <<i+cost[j] << "-" << ans[i+cost[j]] << endl;
        }

      }
    }
    return ans[target] == "" ? "0" : ans[target];
  }
  /*return a > b **/
  bool gao_max(string a, string b)const {
    if(a.length() != b.length())
      return a.length() > b.length() ;
    return a > b;
  }
};
```