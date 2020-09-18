#pragma G++ optimize(2)
#pragma GCC optimize(2)

class Solution {
 public:
  vector<vector<string>> ans;
  vector<int> status;
  int n;

  void gao(int s, int main, int counter, int col) {
    if (s == n) {
      vector<string> str(n, string(n, '.'));
      for (int i = 0; i < n; ++i) str[i][status[i]] = 'Q';
      ans.emplace_back(str);
      return;
    }

    int a = ~(col | (main >> 1) | (counter << 1));
    a &= (1 << n) - 1;
    for (int p = 1, i = 0; p < (1 << n); p <<= 1, i++) {
      if (p & a) {
        status.emplace_back(i);
        gao(s + 1, (main >> 1) | p, (counter << 1) | p, col | p);
        status.pop_back();
      }
    }
  }

  vector<vector<string>> solveNQueens(int _n) {
    n = _n;
    ans.clear();
    gao(0, 0, 0, 0);
    return ans;
  }
};