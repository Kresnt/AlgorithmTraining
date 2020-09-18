class Solution {
 public:
  int minFlips(string target) {
    int ans(0);
    for(int i = 0, st = 0; i < target.length(); i++) {
      if(target[i] - '0' == st)
        continue;
      st ^= 1, ans++;
    }
    return ans;
  }
};
