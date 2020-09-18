typedef long long LL;

class Solution {
 public:
  vector<int> status;
  vector<vector<int>> ans;
  int gao(const vector<int>& candidates, const int p, const int s, const int target) {
    if (s > target)
      return 0;
    else if (s == target) {
      vector<int> r;
      for (int i : status) r.emplace_back(i);
      ans.emplace_back(r);
    } else if (p < candidates.size() && s + candidates[p] <= target) {
      status.emplace_back(candidates[p]);
      gao(candidates, p + 1, s + candidates[p], target);
      status.pop_back();
      gao(candidates, p + 1, s, target);
    }
    return 0;
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    ans.clear();
    status.clear();
    sort(candidates.begin(), candidates.end());
    candidates.erase(upper_bound(candidates.begin(), candidates.end(), target), candidates.end());
    gao(candidates, 0, 0, target);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
  }
};