class Solution {
 public:
  int get_f(vector<int>& f, int v) const { return f[v] = f[v] == v ? v : get_f(f, f[v]); }

  vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
    vector<int>f(n+1);
    for (int i = 0; i <= n; ++i) f[i] = i;
    for (int i = threshold + 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        int u = i, v = j;
        u = get_f(f, u), v = get_f(f,v);
        f[u] = v;
      }
    }
    const int m = queries.size();
    vector<bool> ans(m);
    for (int i = 0; i < m; i++) {
      int u = queries[i][0], v = queries[i][1];
      ans[i] = get_f(f, u) == get_f(f, v);
    }
    return ans;
  }
};