class Solution {
 public:
  int nthUglyNumber(int n, int a, int b, int c) {
    long long first = 0, len = 4e18;
    long long half, middle;
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      if(CountN(middle * 1ll, a * 1ll, b * 1ll, c * 1ll) < n) {
        first = middle + 1;
        len = len - half - 1;
      } else
        len = half;
    }
    return first;
  }

  /**
   * 小于等于 n 的丑数有几个
   */
  long long CountN(long long n, long long a, long long b, long long c) {
    return n / a + n / b + n / c - n / (a * b / __gcd(a, b)) - n / (a * c / __gcd(a, c)) - n / (b * c / __gcd(b, c)) + n / (a * b / __gcd(a, b) * c / (__gcd(__gcd(a, b), c)));
  }
};
