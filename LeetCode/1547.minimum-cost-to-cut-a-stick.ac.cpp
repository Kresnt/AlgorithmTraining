class Solution {
 public:
  int gao(vector<int>&sum)const {
    const int n = sum.size();
    vector<vector<int>>dp(n, vector<int>(n + 7, (1 << 22)));
    for(int i = 0; i < n; ++i)
      dp[i][i] = 0;
    for(int v = 1; v < n; v++) {
      for(int i = 0; i < n - v; i++) {
        int j = i + v;
        dp[i][j] = INT_MAX;
        int tmp = sum[j] - (i > 0 ? sum[i - 1] : 0);
        for(int k = i; k < j; k++)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + tmp);
      }
    }
    return dp[0][n - 1];
  }

  int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    return gao(cuts);
  }
};
