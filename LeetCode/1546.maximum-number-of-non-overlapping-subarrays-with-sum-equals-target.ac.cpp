class Solution {
 public:
  int maxNonOverlapping(vector<int>& nums, int target) {
    map<int, int>g;
    g[0] = {-1};
    int s(0);
    vector<int>ans(nums.size());
    for(int i = 0; i < nums.size(); i++) {
      s += nums[i];
      if(i)
        ans[i] = ans[i - 1];
      if(g.find(s - target) != g.end()) {
        int j = g[s - target];
        ans[i] = max(ans[i], (j >= 0 ? ans[j] + 1 : 1));
      }
      g[s] = (i);
    }
    return ans.back();
  }
};
