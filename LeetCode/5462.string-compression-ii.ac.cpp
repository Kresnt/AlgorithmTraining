class Solution {
 public:
  int getLengthOfOptimalCompression(const string s, const int m) {
    const int n = s.length();
    vector<vector<int>>f(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
    f[0][0] = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j <= m; ++j) {
        if(j + 1 <= m)
          f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
        for(int l = i, d = 0, c = 0; l < n; l++) {
          if(s[l] != s[i])
            d ++;
          else
            c++;
          if(j + d > m)
            break;
          f[l + 1][j + d] = min(f[l + 1][j + d], f[i][j] + 1 + (c > 99 ? 3 : (c > 9 ? 2 : c > 1 ? 1 : 0)));
        }
      }
    }
    return f[n][m];
  }
};
