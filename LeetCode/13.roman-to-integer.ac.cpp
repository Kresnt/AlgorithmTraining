class Solution {
 public:
  int romanToInt(string s) {
    map<char, int>g = {
      {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int ans(0);
    const int n = s.length();
    for(int i = 0; i < n; ++i) {
      int a = 1;
      if(s[i] && i + 1 < n) {
        a = (g[s[i]] < g[s[i + 1]] ? -1 : 1);
      }
      ans += g[s[i]] * a;
    }
    return ans;
  }
};
