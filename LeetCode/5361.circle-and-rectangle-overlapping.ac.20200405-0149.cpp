class Solution {
 public:
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
    long long rr = radius *1ll* radius;
    if(disS(x_center, y_center, x1, y1) > rr && x_center < x1 && y_center < y1)
      return false;
    if(disS(x_center, y_center, x1, y2) > rr && x_center < x1 && y_center > y2)
      return false;
    if(disS(x_center, y_center, x2, y2) > rr && x_center > x2 && y_center > y2)
      return false;
    if(disS(x_center, y_center, x2, y1) > rr && x_center > x2 && y_center < y1)
      return false;

    if(x_center >= x1 && x_center <= x2) {
      if(y_center - radius > y2)
        return false;
      if(y_center + radius < y1)
        return false;
      return true;
    }
    if(y_center >= y1 && y_center <= y2) {
      if(x_center - radius > x2)
        return false;
      if(x_center + radius < x1)
        return false;
      return true;
    }
    return true;
  }
 private:
  long long disS(int x1, int y1, int x2, int y2) {
    long long dx = x1 - x2, dy = y1 - y2;
    return (dx * dx + dy * dy);
  }
};
