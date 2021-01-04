class Solution {
 public:
  bool chk(int k, const vector<int>& s) {
    int x, y;
    if (k & 1) {
      x = s[0] - s[k + 1] + s[k + 2];
      y = s[1] - s[k] + s[k + 1];
    } else {
      x = s[0] - s[k] + s[k + 1];
      y = s[1] - s[k + 1] + s[k + 2];
    }
    return x == y;
  }

  int waysToMakeFair(vector<int>& nums) {
    const int n = nums.size();
    vector<int> s(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) {
      s[i] = (i + 2 < n ? s[i + 2] : 0) + nums[i];
    }
    int ans(0);
    for (int i = 0; i < n; ++i) {
      if (chk(i, s)) ans++;
    }
    return ans;
  }
};