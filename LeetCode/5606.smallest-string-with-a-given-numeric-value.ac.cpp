class Solution {
 public:
  string getSmallestString(int n, int k) {
    k -= n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = n - 1, t; i >= 0 && k; i--) {
      t = min(25, k);
      a[i] += t, k -= t;
    }
    string s;
    for (int i = 0; i < n; ++i) s += a[i] + 'a';
    return s;
  }
};