class Solution {
 public:
  string restoreString(string s, vector<int>& indices) {
    vector<char>ans(s.length());
    for(int i = 0; i < s.length(); i++)
      ans[indices[i]] = s[i];
    s = "";
    for(int i = 0; i < ans.size(); i++)
      s += ans[i];
    return s;
  }
};
