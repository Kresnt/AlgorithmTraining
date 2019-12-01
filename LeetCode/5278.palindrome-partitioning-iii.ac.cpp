class Solution {
 public:
  int palindromePartition(string s, int k) {
    int dp[s.length()][k + 1];
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < s.length(); ++i) { // end with s[i]
      for(int j = 1; j <= k && j <= i + 1; ++j) { // has j segments
        if(j == 1)
          dp[i][j] = transferCost(s, 0, i);
        else
          for(int pre = max(j - 2, 0); pre < i; ++pre) {
            dp[i][j] = min(dp[i][j], dp[pre][j - 1] + transferCost(s, pre + 1, i));
          }
      }
    }
    return dp[s.length() - 1][k];
  }
  int transferCost(string s, int l, int r) {
    int ans(0);
    for(int i = 0; i < (r - l + 1) / 2; ++i)
      if(s[i + l] != s[r - i])
        ans++;
    return ans;
  }
};
