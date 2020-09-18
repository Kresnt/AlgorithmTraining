class Solution {
 public:
  string revert(const string& s, string &ans) {
    for(char c : s)
      ans += c == '0' ? '1' : '0';
    return ans;
  }

  char findKthBit(int n, int k) {
    vector<string>s(n + 1);
    s[1] = "0";
    for(int i = 2; i <= n; ++i) {
      s[i] = s[i - 1];
      s[i] += "1";
      string t;
      revert(s[i - 1], t);
      reverse(t.begin(), t.end());
      s[i] += t;
    }
    return s[n][k - 1];
  }
};
