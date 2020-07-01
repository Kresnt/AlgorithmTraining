class Solution {
 public:
  bool BFS(int s, int t, vector<int>(& g)[27])const {
    queue<int>que;
    vector<bool>vis(27, false);
    que.push(s);
    vis[s] = true;
    while(!que.empty()) {
      int u = que.front();
      if(u == t)
        return true;
      que.pop();
      for(auto v : g[u]) {
        if(!vis[v])
          que.push(v), vis[v] = true;
      }
    }
    return false;
  }

  bool equationsPossible(vector<string>& equations) {
    vector<int>g[27];
    for(auto i : equations) {
      if(i[1] == '=') {
        int u = i[0] - 'a';
        int v = i[3] - 'a';
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    for(auto i : equations) {
      if(i[1] == '!') {
        int u = i[0] - 'a';
        int v = i[3] - 'a';
        if(BFS(u, v, g))
          return false;
      }
    }
    return true;
  }
};
