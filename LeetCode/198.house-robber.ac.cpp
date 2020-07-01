class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    int ans(0);
    vector<int>f(3, 0);
    for(int i = 0; i < n; ++i) {
      if(i - 2 >= 0)
        f[i % 3] = f[(i - 2 + 3) % 3] + nums[i];
      else
        f[i % 3] = nums[i];
      if(i - 1 >= 0)
        f[i % 3] = max(f[i % 3], f[(i - 1 + 3) % 3]);
      ans = max(ans, f[i % 3]);
      cout << f[i % 3] << " ";
    }
    return ans;

  }
};
