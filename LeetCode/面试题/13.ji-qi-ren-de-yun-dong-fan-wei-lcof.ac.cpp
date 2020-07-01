class Solution {
 public:
  int movingCount(int m, int n, int k) {
    static const int dx[] = {+1, -1, 0, 0};
    static const int dy[] = {0, 0, +1, -1};
    vector<int>s(2, 0);
    queue<vector<int> > que;
    map<pair<int, int>, bool>vis;
    que.push(s);
    vis[make_pair(0, 0)] = true;
    int ans(0);
    while(!que.empty()) {
      s = que.front();
      que.pop();
      ans++;
      for(int i = 0; i < 4; ++i) {
        vector<int> f({s[0] + dx[i], s[1] + dy[i]});
        if(inRange(f, m, n) && digitSum(f[0]) + digitSum(f[1]) <= k &&
            !vis[make_pair(f[0], f[1])]) {
          que.push(f);
          vis[make_pair(f[0], f[1])] = true;
        }
      }
    }
    return ans;
  }
 private:
  inline int digitSum(int x) {
    int ans(0);
    while(x) {
      ans += x % 10;
      x /= 10;
    }
    return ans;
  }
  inline bool inRange(vector<int>pos, int m, int n) {
    int &x = pos[0], &y = pos[1];
    return x >= 0 && x < m && y >= 0 && y < n;
  }
};
