class Solution {
 public:
  int numSplits(string s) {
    vector<int>a(26), b(26), c(26);
    for(int i = 0; i < s.length(); i++) {
      c[s[i] - 'a']++;
    }
    int ans(0);
    for(int i = 0; i < s.length(); i++) {
      a[s[i] - 'a']++;
      for(int j = 0; j < 26; ++j)
        b[j] = c[j] - a[j];
      int t(0), tt(0);
      for(int j = 0; j < 26; j++)
        t += b[j] != 0, tt += a[j] != 0;
      if(tt == t)
        ans++;
    }
    return ans;
  }
};
