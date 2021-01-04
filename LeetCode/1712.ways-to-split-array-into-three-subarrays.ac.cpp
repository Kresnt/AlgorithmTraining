class Solution {
 public:
  int waysToSplit(vector<int>& nums) {
    const int n = nums.size();
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
      s[i] = nums[i] + (i ? s[i - 1] : 0);
    }
    int ans(0);
    const int MOD = 1e9 + 7;
    for (int i = 0; i < n - 2 && s[i] <= s[n - 1] / 3; i++) {
      int l, r;
      l = lower_bound(s.begin(), s.end(), s[i] * 2) - s.begin();
      l = max(i + 1, l);
      r = upper_bound(s.begin(), s.end(), s[i] + (s[n - 1] - s[i]) / 2) - s.begin();
      r = min(n - 1, max(r, i + 1));
      ans = (ans + r - l) % MOD;
    }
    return ans;
  }
};