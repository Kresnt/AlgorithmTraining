class Solution {
 public:
  const string d[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void gao(const string& digits, string& s, const int x, vector<string>& ans) {
    if (x == digits.length()) {
      ans.push_back(s);
      return;
    }
    for (char c : d[digits[x] - '0' - 1]) {
      s += c;
      gao(digits, s, x + 1, ans);
      s.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) return ans;
    string s;
    gao(digits, s, 0, ans);
    return ans;
  }
};