class Solution {
 public:
  string findLexSmallestString(string s, int a, int b) {
    queue<string> que;
    set<string> vis;
    que.push(s);
    vis.insert(s);
    string ans(s);
    while (!que.empty()) {
      string u = que.front(), v;
      ans = min(ans, u);
      que.pop();
      v = u;
      for (int i = 0; i < u.length(); i++)
        if (i & 1) v[i] = (u[i] - '0' + a) % 10 + '0';
      if (vis.find(v) == vis.end()) vis.insert(v), que.push(v);
      for (int i = 0; i < u.length(); i++) v[(i + b) % u.length()] = u[i];
      if (vis.find(v) == vis.end()) vis.insert(v), que.push(v);
    }
    return ans;
  }
};