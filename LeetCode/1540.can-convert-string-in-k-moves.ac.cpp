class Solution {
 public:
  bool canConvertString(string s, string t, int k) {
    if(s.length() != t.length())
      return false;
    map<int, int>vis;
    for(int i = 0, c; i < s.length(); i++) {
      if(s[i] == t[i])
        continue;
      if(s[i] < t[i])
        c = t[i] - s[i];
      else
        c = 26 - s[i] + t[i];
      if(c + vis[c] * 26 > k)
        return false;
      vis[c]++;
    }
    return true;
  }
};
