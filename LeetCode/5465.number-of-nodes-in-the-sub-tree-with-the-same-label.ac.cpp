class Solution {
 public:
  vector<int> DFS(int root, int fa, vector<int>&ans, const vector<vector<int>>&g, const string &labels) {
    vector<int>cnt(26, 0);
    cnt[labels[root] - 'a']++;
    for(int v : g[root]) {
      if(v == fa)
        continue;
      vector<int>delta = DFS(v, root, ans, g, labels);
      for(int j = 0; j < 26; ++j)
        cnt[j] += delta[j];
    }
    ans[root] = cnt[labels[root] - 'a'];
    return cnt;
  }

  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    if(n == 0)
      return {};
    vector<int>ans(n);
    vector<vector<int>>g(n);
    for(vector<int>edge : edges) {
      g[edge[0]].push_back(edge[1]);
      g[edge[1]].push_back(edge[0]);
    }
    DFS(0, -1, ans, g, labels);
    return ans;
  }
};
