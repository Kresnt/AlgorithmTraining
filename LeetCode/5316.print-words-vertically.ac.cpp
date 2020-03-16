class Solution {
 public:
  vector<string> printVertically(string s) {
    vector<string> words;
    for(int i = 0, len = s.length(); i < len; ++i) {
      string t;
      while(s[i] != ' ' && i < len)
        t += s[i++];
      words.push_back(t);
    }
    //for(auto s:words) cout << s << ",";

    const int m = words.size();
    const int n = getMaxLengthOfWord(words);
    //cout << n << " " << m << endl;
    vector<string>ans(n);
    for(int i = 0; i < n; ++i) {
      bool lastNull = true;
      ans[i] = "";
      for(int j = m - 1; j >= 0; --j) {
        if(words[j].length() <= i && lastNull)
          continue;
        else if(words[j].length() <= i)
          ans[i] += ' ';
        else {
          ans[i] += words[j][i];
          lastNull = false;
        }
      }
      reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
  }

 private:
  int getMaxLengthOfWord(vector<string> &words) {
    int ans(0);
    for(string s : words)
      ans = ans < s.length() ? s.length() : ans;
    return ans;
  }
};
