class Solution {
 public:
  const int n = 26;
  vector<int>fa;

  int get_fa(int u) {
    return fa[u] = (fa[u] == u ? u : get_fa(fa[u]));
  }

  bool equationsPossible(vector<string>& equations) {
    fa = vector<int>(26);
    for(int i = 0; i < n; ++i)
      fa[i] = i;
    for(auto i : equations) {
      int u = i[0] - 'a';
      int v = i[3] - 'a';
      if(i[1] == '=') {
        fa[get_fa(u)] = get_fa(v);
      }
    }
    for(auto i : equations) {
      int u = i[0] - 'a';
      int v = i[3] - 'a';
      if(i[1] != '=') {
        if(get_fa(u) == get_fa(v))
          return false;
      }
    }
    return true;
  }
};
