class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    const int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    int ans(0);
    int zs = 0;
    while(zs < n && satisfaction[zs] < 0)
      zs++;
    if(zs == n)
      return 0;

    for(int b = zs; b >= 0; --b) {
      int t = calV(b, satisfaction);
      if(ans < t) {
        ans = t;
      } else if(ans > t)
        break;
    }
    return ans;

  }
 private:
  int calV(int b, vector<int>& satisfaction) {
    int ans(0);
    const int n = satisfaction.size();
    for(int i = b, j = 1; i < n; ++i, ++j) {
      ans += satisfaction[i] * j;
    }
    return ans;
  }
};
