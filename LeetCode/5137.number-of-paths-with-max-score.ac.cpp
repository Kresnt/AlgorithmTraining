class Solution {
  typedef pair<int, int>PII;
  const static int MOD = 1e9 + 7;
 public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    int n = board.size(), m = board[0].length();
    vector<vector<PII>> g(m, vector<PII>(n, PII(0, 0)));
    g[n - 1][m - 1] = PII(0, 1);
    for(int i = m - 2; i >= 0 && board[n - 1][i] != 'X'; --i)
      g[n - 1][i] = PII(board[n - 1][i] - '0' + g[n - 1][i + 1].first, g[n - 1][m - 1].second);
    for(int i = n - 2; i >= 0; --i) {
      for(int j = m - 1; j >= 0; --j) {
        if(board[i][j] == 'X')
          continue;
        g[i][j] = PII(0, 0);
        if(board[i + 1][j] != 'X')
          modify(g[i][j], g[i + 1][j]);
        if(j + 1 < m) {
          if(board[i + 1][j + 1] != 'X')
            modify(g[i][j], g[i + 1][j + 1]);
          if(board[i][j + 1] != 'X')
            modify(g[i][j], g[i][j + 1]);
        }
        if(board[i][j] >= '0' && board[i][j] <= '9')
          g[i][j].first += board[i][j] - '0';
      }
    }
    vector<int>ans(2);
    ans[0] = g[0][0].first, ans[1] = g[0][0].second;
    if(ans[1] == 0)
      ans[0] = 0;
    return ans;
  }

  inline void modify(PII& a, PII& b) {
    if(a.first != b.first)
      a = max(a, b);
    else if(a.first == b.first && b.second)
      a.second = (a.second + b.second) % MOD;
  }
};
