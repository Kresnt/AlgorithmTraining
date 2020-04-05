class Solution {
 public:
  int numSteps(string s) {
    int ans(0);
    while(s != "1") {
      ans ++;
      const int n = s.length();
      cout << s  << endl;
      if(s[n - 1] == '0') {
        s.erase(s.end() - 1);
      } else if(s.find_last_of("0") != string::npos) {
        s[s.find_last_of("0")] = '1';
      } else {
        s = "1";
        for(int i = 0; i < n; ++i)
          s += "0";
      }

    }
    return ans;
  }
};
