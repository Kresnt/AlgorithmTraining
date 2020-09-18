class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> d(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++) d[i][1] = nums[i];
    for (int i = 2; i <= n; i++) {
      for (int j = 0; i + j - 1 < n; j++) {
        d[j][i] = max(-d[j][i - 1] + nums[j + i - 1], -d[j + 1][i - 1] + nums[j]);
      }
    }
    return d[0][n] > 0;
  }
};