class Solution {
 public:
  vector<vector<int>> ans;
  int gao(const vector<int>& candidates, vector<pair<int, int>>& status, const int p, const int s, const int target) {
    if (s > target)
      return 0;
    else if (s == target) {
      vector<int> r;
      for (pair<int, int> pii : status)
        for (int j = 0; j < pii.first; j++) r.emplace_back(pii.second);
      ans.emplace_back(r);
    } else if (p < candidates.size() && s + candidates[p] <= target) {
      for (int i = (target - s) / candidates[p]; i > 0; --i) {
        status.emplace_back(make_pair(i, candidates[p]));
        gao(candidates, status, p + 1, s + i * candidates[p], target);
        status.pop_back();
      }
      gao(candidates, status, p + 1, s, target);
    }
    return 0;
  }

  vector<vector<int>> combinationSum(const vector<int>& candidates, int target) {
    ans.clear();
    vector<pair<int, int>> status;
    sort(candidates.begin(), candidates.end());
    gao(candidates, status, 0, 0, target);
    return ans;
  }
};