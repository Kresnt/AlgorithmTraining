using std::vector;
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int n = groupSizes.size();
    vector<vector<int>> ans;
    vector<int> g[n + 1];
    for(int i = 0; i < n; ++i) {
      g[groupSizes[i]].push_back(i);
      if(g[groupSizes[i]].size() == groupSizes[i]) {
        ans.push_back(g[groupSizes[i]]);
        g[groupSizes[i]].clear();
      }
    }
    return ans;
  }
};