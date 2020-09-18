class Solution {
 public:
  int longestAwesome(string s) const {
    vector<int>a(s.length() + 1, 0);
    vector<int>g((1 << 11), -1);
    for(int i = 0; i < s.length(); i++) {
      a[i + 1] = a[i] ^ (1 << (s[i] - '0'));
    }
    int ans(0);
    for(int i = 0; i <= s.length(); i++) {
      if(g[a[i]] == -1)
        g[a[i]] = i;
      ans = max(ans, i - g[a[i]]);
      int t = a[i];
      for(int j = 0; j < 10; j++) {
        t = a[i] ^ (1 << j);
        if(g[t] != -1)
          ans = max(ans, i - g[t]);
      }
    }

    return ans;
  }
};
