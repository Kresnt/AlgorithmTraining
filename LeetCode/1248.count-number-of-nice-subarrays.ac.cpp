class Solution {
 public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    const int n = nums.size();
    vector<int> c(n + 1);
    int ans(0);
    c[0] = 0;
    for (int i = 0; i < n; ++i) {
      c[i + 1] = c[i] + (nums[i] & 1);
    }
    for (int i = 0, prev; i < n + 1; ++i) {
      if (c[i] >= k) {
        if(c[i] != c[i - 1])
          prev = upper_bound(c.begin(), c.end(), c[i] - k) - lower_bound(c.begin(), c.end(), c[i] - k);
        ans += prev;
      }
    }
    return ans;
  }
};
