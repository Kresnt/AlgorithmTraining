class Solution {
 public:
  int countLargestGroup(int n) {
    const int maxn = 1e4 + 7;
    map<int, int>g;
    for(int i  = 1; i <= n; ++i) {
      g[parse(i)]++;
      //cout << parse(i) << " " << i <<"\n";
    }
    vector<int> ans(maxn, 0);
    for(map<int, int>::iterator it = g.begin(); it != g.end(); it++) {
      ans[it->second]++;
    }
    //for(int i = 0;i < 100;++i) cout << ans[i] << " ";
    int ret = maxn - 1;
    while(ans[ret] == 0)
      ret--;
    return ans[ret];
  }
 private :
  int parse(int x) {
    int ans(0);
    while(x) {
      ans += x % 10;
      x /= 10;
    }
    return ans;
  }
};
