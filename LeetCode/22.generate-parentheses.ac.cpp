class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    ans = new vector<string>();
    DFS(n, 0, "");
    return ans;
  }
 private:
  vector<string>ans;
  void DFS(int n, int left, string s) {
    if(n == 0) {
      while(left --)
        s += ")";
      ans.push_back(s);
      return ;
    } else {
      DFS(n - 1, left + 1, s + "(", ans);
      if(left > 0)
        DFS(n, left - 1, s + ")", ans);
    }
  }
};
