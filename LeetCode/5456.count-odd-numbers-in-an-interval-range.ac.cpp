class Solution {
 public:
  int countOdds(int low, int high) {
    int ans(0);
    if(low & 1)
      low++, ans++;
    if(high > low && high & 1)
      high--, ans++;
    if(low < high)
      ans += (high - low) / 2;
    return ans;
  }
};
