class Solution {
 public:
  double myPow(double x, int nn) {
    double ans(1.0);
    int sig = (nn < 0 ? -1 : 1);
    long long n = abs(nn);

    if(n == 0)
      return 1;
    if(x == 1.0)
      return 1.0;

    while(n) {
      if(n & 1)
        ans = ans * x;
      x = x * x;
      n >>= 1;
    }
    if(sig == -1)
      return 1.0 / ans;
    return ans;
  }
};
