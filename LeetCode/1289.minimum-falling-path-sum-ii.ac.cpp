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