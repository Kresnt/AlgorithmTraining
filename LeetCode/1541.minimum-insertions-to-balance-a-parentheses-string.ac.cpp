class Solution {
 public:

  int gao(string &s)const {
    int l(0), r(0);
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '(')
        l++;
      else if(s[i] == ')') {
        if(l > 0)
          l--;
        else
          r++;
      }
    }
    return 2 * l + r;
  }

  int minInsertions(string s) {
    string t;
    int ans(0);
    for(int i = 0; i < s.length(); i++) {
      t += s[i];
      if(s[i] == ')') {
        if((i + 1 < s.length() && s[i + 1] == ')'))
          i++;
        else
          ans++;
      }
    }
    return ans + gao(t);
  }
};
