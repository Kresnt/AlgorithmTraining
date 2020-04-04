class Solution {
 public:
  bool canConstruct(string s, int k) {
    int c[26] = {0};
    const int n = s.length();
    if(n < k)
      return false;
    for(int i = 0; i < n; ++i) {
      c[s[i] - 'a']++;
    }
    int ret = 0;
    for(int i = 0; i < 26; ++i) {
      if(c[i] & 1)
        ret ++;
    }
    return ret <= k;
  }
};
