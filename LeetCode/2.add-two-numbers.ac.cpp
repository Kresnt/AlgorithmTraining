class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
      return "";
    string ans(strs[0]);
    for(int i = 1, n = strs.size(); i < n; ++i) {
      ans = cp(ans, strs[i]);
    }
    return ans;
  }

  string cp(string &a, string &b)const {
    string ans;
    for(int i = 0; i < min(a.size(), b.size()); ++i) {
      if(a[i] == b[i])
        ans += a[i];
      else
        break;
    }
    return ans;
  }
};
