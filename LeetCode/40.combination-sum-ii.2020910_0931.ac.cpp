class Solution {
 public:
  vector<int> status;
  vector<vector<int>> ans;
  vector<int> nums;

  void gao(int x, int target) {
    if (target == 0) {
      ans.emplace_back(status);
      return;
    }
    for (int i = x; i < nums.size(); i++) {
      if (i > x && nums[i] == nums[i - 1]) continue;
      if (target < nums[i]) break;
      status.emplace_back(nums[i]);
      gao(i + 1, target - nums[i]);
      status.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    this->nums = move(candidates);
    sort(nums.begin(), nums.end());
    gao(0, target);
    return ans;
  }
};