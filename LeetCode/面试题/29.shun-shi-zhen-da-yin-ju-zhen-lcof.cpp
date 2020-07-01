class Solution {
 public:

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    if(n == 0)
      return {};
    const int m = matrix[0].size();
    vector<int>ans(n * m);
    int idx = 0;
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    int x = 0, y = 0;
    while(idx < n * m) {
      // cout << x << " " << y << endl;
      while(y < m && !vis[x][y]) {
        ans[idx++] = matrix[x][y];
        vis[x][y] = true, y++;
      }
      y--, x++;
      // cout << x << " " << y << endl;
      while(x < n && !vis[x][y]) {
        ans[idx++] = matrix[x][y];
        vis[x][y] = true, x++;
      }
      x--, y--;
      // cout << x << " " << y << endl;
      while(y >= 0 && !vis[x][y]) {
        ans[idx++] = matrix[x][y];
        vis[x][y] = true, y--;
      }
      y++, x--;
      // cout << x << " " << y << endl;
      while(x >= 0 && !vis[x][y]) {
        ans[idx++] = matrix[x][y];
        vis[x][y] = true, x--;
      }
      x++, y++;
      // cout << c << endl;
    }
    return ans;
  }
};
