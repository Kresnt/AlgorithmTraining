class Solution {
 public:
  inline bool is_lower(char c) {return c >= 'a' && c <= 'z';}
  string makeGood(string s) {
    string ans;
    for(int i = 0; i < s.length(); i++) {
      if(ans.length() > 0) {
        if(is_lower(ans.back()) && s[i] == ans.back() + 'A' - 'a')
          ans.pop_back();
        else if(is_lower(s[i]) && ans.back() == s[i] + 'A' - 'a')
          ans.pop_back();
        else
          ans += s[i];
      } else
        ans += s[i];
    }
    return ans;
  }
};
