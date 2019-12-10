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