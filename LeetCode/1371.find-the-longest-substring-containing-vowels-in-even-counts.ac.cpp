class Solution {
 public:
  int findTheLongestSubstring(string s) {
    const string vowels("aeiou");
    vector<vector<int>>g(1 << 5);
    int t = 0;
    g[0].push_back(0);
    for(int i = 0, n = s.length(); i < n; ++i) {
      for(int j = 0; j < vowels.length(); ++j) {
        if(s[i] == vowels[j])
          t ^= 1 << j;
      }
      if(g[t].size() < 2)
        g[t].push_back(i + 1);
      else
        g[t][1] = i + 1;
    }
    int ans(0);
    for(int i = 0; i < (1 << 5); ++i) {
      if(g[i].size() > 1)
        ans = max(ans, g[i].back() - g[i][0]);
    }
    return ans;
  }
};
