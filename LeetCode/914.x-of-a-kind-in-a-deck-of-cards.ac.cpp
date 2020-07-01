class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    map<int, int> g;
    for(int i : deck)
      g[i]++;
    int ans(0);
    for(map<int, int>::iterator it = g.begin(); it != g.end(); it++) {
      if(ans == 0)
        ans = it->second;
      else {
        ans = __gcd(ans, it->second);
      }
    }
    return ans > 1;
  }
};
