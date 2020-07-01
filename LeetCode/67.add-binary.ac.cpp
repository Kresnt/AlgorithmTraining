#pragma G++ optimize("O2")

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int c = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0, j = 0; i < a.length() || j < b.length();) {
      if(i < a.length())
        c += a[i] - '0', i++;
      if(j < b.length())
        c += b[j] - '0', j++;
      ans += c % 2 + '0';
      c /= 2;
    }
    if(c)
      ans += c % 2 + '0';
    reverse(ans.begin(), ans.end());
    if(ans.length() == 0)
      return "0";
    return ans;
  }
};
