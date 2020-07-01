class Solution {
 public:
  int translateNum(int num) {
    string s = to_string(num);
    const int n = s.length();
    vector<int>ans(n + 1);
    ans[0] = 1;
    for(int i = 0; i < n; ++i) {
      ans[i + 1] += ans[i];
      if(i && s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' < 26)
        ans[i + 1] += ans[i - 1];
    }
    return ans[n];
  }
};
