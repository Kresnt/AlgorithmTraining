class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    const int maxm = 10000 + 7;
    const int n = A.size();
    int c[maxm] = {0};
    int ans = 0;
    c[0] = 1;
    for(int i = 0, l = 0; i < n; ++i) {
      l = (l + A[i] % K + K) % K;
      c[l]++;
      ans += c[l] - 1;
    }
    return ans;
  }
};
