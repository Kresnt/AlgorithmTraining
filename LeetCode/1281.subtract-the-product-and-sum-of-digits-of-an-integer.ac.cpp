class Solution {
 public:
  int p(int n) {
    int ans(1);
    while(n)
      ans *= n % 10, n /= 10;
    return ans;
  }
  int s(int n) {
    int ans(0);
    while(n)
      ans += n % 10, n /= 10;
    return ans;
  }

  int subtractProductAndSum(int n) {
    return p(n) - s(n);
  }
};