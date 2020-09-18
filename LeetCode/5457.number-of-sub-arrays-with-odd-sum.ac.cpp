class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    const int mod = 1e9 + 7;
    vector<vector<int>>f(arr.size(), vector<int>(2, 0));
    int ans(0);
    for(int i = 0; i < arr.size(); ++i) {
      if(i == 0) {
        if(arr[i] & 1)
          f[i][1] ++;
        else
          f[i][0]++;
      } else {
        if(arr[i] & 1)
          f[i][1] = (f[i - 1][0] + 1) % mod, f[i][0] = (f[i - 1][1]) % mod;
        else
          f[i][1] = f[i - 1][1] % mod, f[i][0] = f[i - 1][0] % mod + 1;
      }
      ans = (ans + f[i][1]) % mod;
    }
    return ans;
  }
};
