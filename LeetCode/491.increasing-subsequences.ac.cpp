// binary brute foce
class Solution {
 public:
  int c(int x) {
    int c(0);
    while (x) c += x & 1,x >>= 1;
    return c;
  }

  void gao(const vector<int>& nums, const int flag, vector<vector<int>>& ans) {
    if (c(flag) < 2) return;
    vector<int> v(c(flag));
    for (int i = 0, j = 0; i < nums.size(); i++)
      if (flag & (1 << i)) v[j++] = (nums[i]);
    for (int i = 1; i < v.size(); i++)
      if (v[i] < v[i - 1]) return;
    ans.emplace_back(v);
  }

  vector<vector<int>> findSubsequences(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << n); i++) gao(nums, i, ans);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};