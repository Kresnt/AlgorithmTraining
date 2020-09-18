class Solution {
 public:
  int maxSum(vector<int>& nums1, vector<int>& nums2) const {
    set<int>s;
    long long ans(0);
    const long long mod = 1e9 + 7;
    for(int i : nums1)
      s.insert(i), ans = max(ans, i * 1ll);
    for(int i : nums2)
      s.insert(i), ans = max(ans, i * 1ll);
    vector<long long>dp(ans + 1);
    int p(0), q(0);
    for(int i : s) {
      if(p < nums1.size() && nums1[p] == i) {
        dp[i] = max(dp[i], (p == 0 ? 0 : dp[nums1[p - 1]]) + nums1[p]);
        p++;
      }
      if(q < nums2.size() && nums2[q] == i) {
        dp[i] = max(dp[i], (q == 0 ? 0 : dp[nums2[q - 1]]) + nums2[q]);
        q++;
      }
      ans = max(ans, dp[i]);
    }
    return ans % mod;
  }
};
