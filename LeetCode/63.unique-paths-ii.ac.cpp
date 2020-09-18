class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int n = obstacleGrid.size();
    const int m = obstacleGrid[0].size();
    vector<vector<int>>f(n, vector<int>(m, 0));
    f[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for(int i = 1; i < m; ++i)
      f[0][i] = obstacleGrid[0][i] == 1 ? 0 : f[0][i - 1];
    for(int i = 1; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(obstacleGrid[i][j])
          f[i][j] = 0;
        else
          f[i][j] = f[i - 1][j] + (j ? f[i][j - 1] : 0);
      }
    }
    return f[n - 1][m - 1];
  }
};
