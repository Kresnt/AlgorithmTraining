# LeetCode 第 15 场双周赛

[1287.有序数组中出现次数超过25%的元素](https://leetcode-cn.com/problems/Element-Appearing-More-Than-25-In-Sorted-Array)

[1288.删除被覆盖区间](https://leetcode-cn.com/problems/Remove-Covered-Intervals)

[1286.字母组合迭代器](https://leetcode-cn.com/problems/Iterator-for-Combination)

[1289.下降路径最小和  II](https://leetcode-cn.com/problems/Minimum-Falling-Path-Sum-II)

<!-- more -->

下降和不能只保留原数组中最小的两个，hacked.

# 1287.有序数组中出现次数超过25%的元素
[1287.有序数组中出现次数超过25%的元素](https://leetcode-cn.com/problems/Element-Appearing-More-Than-25%-In-Sorted-Array)

给你一个非递减的  **有序** 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

请你找到并返回这个整数



**示例：**



    **输入：** arr = [1,2,2,6,6,6,6,7,10]
    **输出：** 6



## 提示 Hint
**提示：**

  * `1 <= arr.length <= 10^4`
  * `0 <= arr[i] <= 10^5`


## 代码
```c++
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(),val = arr[0];
        pair<int,int>ans({0,0});
        for(int i = 0,c = 0;i < n;++i){
          if(arr[i] == val)  c++,ans=max(ans,make_pair(c,val));
          else c = 1,val = arr[i];
        }
        return ans.second;
    }
};
```

# 1288.删除被覆盖区间
[1288.删除被覆盖区间](https://leetcode-cn.com/problems/Remove Covered Intervals)

给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 `c <= a` 且 `b <= d` 时，我们才认为区间 `[a,b)` 被区间 `[c,d)` 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。



**示例：**



    **输入：** intervals = [[1,4],[3,6],[2,8]]
    **输出：** 2
    **解释：** 区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。



## 提示 Hint
**提示：** ​​​​​​

  * `1 <= intervals.length <= 1000`
  * `0 <= intervals[i][0] < intervals[i][1] <= 10^5`
  * 对于所有的 `i != j`：`intervals[i] != intervals[j]`


## 代码

```c++
class Solution {
  typedef pair<int, int>PII;
 public:

  static bool cmp(vector<int>& a, vector<int>& b) {
    return (a[0] != b[0]) ? (a[0] < b[0]) : (a[1] > b[1]);
  }

  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    const int n = intervals.size();
    sort(intervals.begin(), intervals.end(), cmp);
    int l = intervals[0][1], ans = 1;
    for(int i = 1; i < n; ++i) {
      if(intervals[i][1] > l)
        ans++, l = intervals[i][1];
    }
    return ans;
  }
};
```

# 1286.字母组合迭代器
[1286.字母组合迭代器](https://leetcode-cn.com/problems/Iterator-for-Combination)

请你设计一个迭代器类，包括以下内容：

  * 一个构造函数，输入参数包括：一个  **有序且字符唯一  **的字符串 `characters`（该字符串只包含小写英文字母）和一个数字 `combinationLength` 。
  * 函数  _next()  _，按  **字典序  **返回长度为 `combinationLength` 的下一个字母组合。
  * 函数  _hasNext()  _，只有存在长度为 `combinationLength` 的下一个字母组合时，才返回 `True`；否则，返回 `False`。



**示例：**



    CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器 iterator

    iterator.next(); // 返回 "ab"
    iterator.hasNext(); // 返回 true
    iterator.next(); // 返回 "ac"
    iterator.hasNext(); // 返回 true
    iterator.next(); // 返回 "bc"
    iterator.hasNext(); // 返回 false



## 提示 Hint
**提示：**

  * `1 <= combinationLength <= characters.length <= 15`
  * 每组测试数据最多包含 `10^4` 次函数调用。
  * 题目保证每次调用函数 `next` 时都存在下一个字母组合。


## 代码
```c++
class CombinationIterator {
 public:
  string characters;
  string cur;
  int combinationLength;
  bool first;
  CombinationIterator(string characters, int combinationLength) {
    this->characters = characters;
    this->combinationLength = combinationLength;
    this->cur = characters.substr(0, combinationLength);
    this->first = true;
  }

  string next() {
    if(first) {
      first = false;
      return cur;
    }
    vector<int>pos;
    for(int i = 0; i < combinationLength; i++) {
      pos.push_back(characters.find_first_of(cur[i]));
    }
    for(int i = pos.size() - 1; i >= 0; --i) {
      if((i == pos.size() - 1 && pos[i] < characters.length() - 1)
          || (i < pos.size() - 1 && pos[i] + 1 != pos[i + 1])) {
        shiftPos(pos, i);
        break;
      }
    }
    cur = "";
    for(int i = 0, sz = pos.size(); i < sz; ++i)
      cur += characters[pos[i]];
    return cur;
  }

  void shiftPos(vector<int>&pos, int i) {
    pos[i]++;
    for(int j = i + 1; j < combinationLength; ++j)
      pos[j] = pos[j - 1] + 1;
  }

  bool hasNext() {
    vector<int>pos;
    for(int i = 0; i < combinationLength; i++) {
      pos.push_back(characters.find_first_of(cur[i]));
    }
    //for(auto i : pos) cout << i << " "; cout << endl;
    if(pos[0] == characters.length() - combinationLength)
      return false;
    return true;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 ```

# 1289.下降路径最小和  II
[1289.下降路径最小和  II](https://leetcode-cn.com/problems/Minimum-Falling-Path-Sum-II)

给你一个整数方阵 `arr` ，定义「非零偏移下降路径」为：从 `arr` 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。

请你返回非零偏移下降路径数字和的最小值。


## 样例输入与样例输出 Sample Input and Sample Output
**示例 1：**



    **输入：** arr = [[1,2,3],[4,5,6],[7,8,9]]
    **输出：** 13
    **解释：**
    所有非零偏移下降路径包括：
    [1,5,9], [1,5,7], [1,6,7], [1,6,8],
    [2,4,8], [2,4,9], [2,6,7], [2,6,8],
    [3,4,8], [3,4,9], [3,5,7], [3,5,9]
    下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。



## 提示 Hint
**提示：**

  * `1 <= arr.length == arr[i].length <= 200`
  * `-99 <= arr[i][j] <= 99`


## 代码
```c++
class Solution {
 public:
  static const int inf = 0x3f3f3f3f;
  int minFallingPathSum(vector<vector<int>>& arr) {
    int n = arr.size(), m = arr[0].size();
    int s[n][m];
    for(int j = 0; j < m; ++j)
      s[0][j] = arr[0][j];
    for(int i = 1; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        s[i][j] = inf;
        for(int k = 0; k < m; ++k) {
          if(k == j) continue;
          s[i][j] = min(s[i][j], s[i - 1][k] + arr[i][j]);
        }
      }
    }
    int ans = inf;
    for(int i = 0;i < m;++i) ans = min(ans,s[n-1][i]);
    return ans;
  }
};
```
