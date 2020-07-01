class Solution {
 public:
  int mySqrt(int x) {
    int a = 0;
    while((a + 1) <= x / (a + 1))
      a++;
    return a;
  }
};

/***********************************/

class Solution {
 public:
  int mySqrt(int x) {
    int first = 0;
    int len = INT_MAX;
    int half, middle;

    if(!x)
      return 0;
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      if(middle > x / middle) {
        len = half;
      } else {
        first = middle + 1;
        len = len - half - 1;
      }
    }
    return first - 1;
  }
};

/*************************/

class Solution {
 public:
  int mySqrt(int a) {
    const double eps = 1e-8;
    double x, x0, f, f1;
    x = 1;
    do {
      x0 = x;
      f = x0 * x0 - a;
      f1 = 2 * x0;
      x = x0 - f / f1;
    } while(fabs(x - x0) > eps);
    return (int)floor(x);
  }
};
