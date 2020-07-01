#pragma G++ optimize("O2")

// Solution 1
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    const int n = T.size();
    vector<int>ans(n, 0);
    ans[n - 1] = 0;
    for(int i = n - 2, j; i >= 0; --i) {
      j = 1;
      while(T[i + j] <= T[i]) {
        if(ans[i + j])
          j += ans[i + j];
        else
          break;
      }
      if(T[i + j] > T[i])
        ans[i] = j;
    }
    return ans;
  }
};

// Solution 2
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    const int n = T.size();
    vector<int> res(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; i ++) {
      while (!stk.empty() && T[i] > T[stk.top()]) {
        res[stk.top()] = i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }
    return res;
  }
};
