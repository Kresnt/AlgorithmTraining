#pragma GCC optimize("O3")
#pragma G++ optimize("O3")

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    const int n = nums.size();
    unordered_map<int, int>g;
    int s(0);
    int ans(0);
    g[0]++;
    for(int i = 0; i < n; ++i) {
      s += nums[i];
      ans += g[s - k];
      g[s]++;
    }
    return ans;
  }
};