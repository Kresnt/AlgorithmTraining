class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<int> c(26, -1);
    int ans(-1);
    for (int i = 0; i < s.length(); i++) {
      int ch = s[i]-'a';
      if (c[ch] != -1)
        ans = max(ans, i - c[ch]);
      else
        c[ch] = i;
    }
    return ans == -1 ? -1 : ans-1;
  }
};