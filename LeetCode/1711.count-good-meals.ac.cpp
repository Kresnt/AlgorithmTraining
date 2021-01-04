class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    const int maxn = (1 << 21) + 7;
    int g[maxn] = {0};
    int ans(0);
    const int MOD = 1e9 + 7;
    const int n = deliciousness.size();
    for (int i : deliciousness) g[i]++;
    set<int> s;
    for (int i : deliciousness) s.insert(i);
    for (int i = 1; i <= (1 << 21); (i <<= 1)) {
      for (int a : s) {
        int b = i - a;
        if (a < b)
          ans = (ans + g[a] * g[b]) % MOD;
        else if (a == b)
          ans = (ans + g[a] * (g[b] - 1ll) / 2) % MOD;
      }
    }
    return ans;
  }
};