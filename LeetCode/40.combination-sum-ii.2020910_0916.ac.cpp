typedef vector<pair<int,int>>VPII;

class Solution {
 public:
  VPII status;
  vector<vector<int>> ans;
  int gao(const VPII& candidates, const int p, const int s, const int target) {
    if (s > target)
      return 0;
    else if (s == target) {
      vector<int> r;
      for (pair<int, int> pii : status) for (int j = 0; j < pii.first; j++) r.emplace_back(pii.second);
      ans.emplace_back(r);
    } else if (p < candidates.size() && s + candidates[p].first <= target) {
      for (int i = min((target - s) / candidates[p].first, candidates[p].second); i > 0; --i) {
        status.emplace_back(make_pair(i, candidates[p].first));
        gao(candidates,  p + 1, s + i * candidates[p].first, target);
        status.pop_back();
      }
      gao(candidates,  p + 1, s, target);
    }
    return 0;
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    ans.clear();
    status.clear();
    sort(candidates.begin(), candidates.end());
    candidates.erase(upper_bound(candidates.begin(), candidates.end(), target), candidates.end());
    VPII v;
    for(int i:candidates){
      if(v.empty()||i!=v.back().first){
        v.emplace_back(make_pair(i,1));
      }else v.back().second++;
    }
    gao(v, 0, 0, target);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
  }
};