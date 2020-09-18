// DFS
class Solution {
 public:
  void gao(int p, vector<int> cur, const vector<int>& nums, vector<vector<int>>& ans) {
    if (p >= nums.size()) {
      if (cur.size() > 1) ans.emplace_back(cur);
      return;
    }
    if (cur.empty() || nums[p] >= cur.back()) {
      cur.emplace_back(nums[p]);
      gao(p + 1, cur, nums, ans);
      cur.pop_back();
    }
    if (p < nums.size() && !cur.empty() && nums[p] == cur.back()) return;
    gao(p + 1, cur, nums, ans);
  }

  vector<vector<int>> findSubsequences(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> ans;
    if (n < 2) return ans;
    gao(0, {}, nums, ans);
    return ans;
  }
};