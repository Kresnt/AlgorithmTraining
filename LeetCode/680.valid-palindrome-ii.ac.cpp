class Solution {
 public:
  bool validPalindrome(string s) {
    if(s.length() <= 1)
      return true;
    return DFS(s, 0, s.length() - 1, true);
  }

  bool DFS(string &s, int p, int q, bool flag) {
    if(p >= q)
      return true;
    //cout << p << " " << q << " " << flag << endl;
    if(s[p] == s[q])
      return DFS(s, p + 1, q - 1, flag);
    if(flag)
      return DFS(s, p + 1, q, false) || DFS(s, p, q - 1, false);
    return false;
  }
};
