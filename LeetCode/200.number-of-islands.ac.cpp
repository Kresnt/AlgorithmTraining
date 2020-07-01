class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    const int n = grid.size();
    if(n == 0)
      return 0;
    const int m = grid[0].size();
    if(m == 0)
      return 0;
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    queue<pair<int, int> >que;
    int ans(0);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(vis[i][j] || grid[i][j] != '1')
          continue;
        ans++;
        que.push(make_pair(i, j));
        while(!que.empty()) {
          pair<int, int> p = que.front();
          que.pop();
          for(int k = 0; k < 4; ++k) {
            int x = p.first + dx[k];
            int y = p.second + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y]) {
              vis[x][y] = true;
              que.push(make_pair(x, y));
            }
          }
        }
      }
    }
    return ans;
  }
};
