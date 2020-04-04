namespace CG {
const double eps = 1e-10;
int dcmp(double x) {
  if(fabs(x) < eps)
    return 0;
  return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point(): x(0), y(0) {}
  Point(double _x, double _y): x(_x), y(_y) {}
  Point(int _x, int _y): x(_x), y(_y) {}
};
typedef Point Vector;
Vector operator - (Point& A, Point& B) {
  return Vector(A.x - B.x, A.y - B.y);
}
bool operator==(Vector& A, Vector& B) {
  return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}
double Dot(Vector A, Vector B) {
  return A.x * B.x + A.y * B.y;
}
double Length(Vector A) {
  return sqrt(Dot(A, A));
}
double Cross(Vector A, Vector B) {
  return A.x * B.y - A.y * B.x;
}
void DistanceToSegment(Point P, Point A, Point B, double &L, double &R) {
  if(A == B)
    R = L = Length(P - A); //R返回点P到线段的最大距离,L返回最小距离
  else {
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if(dcmp(Dot(v1, v2)) < 0)
      L = Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0)
      L = Length(v3);
    else
      L = fabs(Cross(v1, v2)) / Length(v1);
    R = max(Length(v2), Length(v3));
  }
}
}

using namespace CG;

class Solution {
 public:
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
    double x = x_center, y = y_center;
    double r = radius;
    // 圆在矩形内
    if((x < max(x1, x2) && x > min(x1, x2)) && (y > min(y1, y2) && y < max(y1, y2)))
      return true;
    if(x1 > x2)
      swap(x1, x2);
    if(y1 > y2)
      swap(y1, y2);
    Point p[4], c(x, y); //p[4]是矩形的4个点,c是圆心
    p[0] = Point(x1, y1);
    p[1] = Point(x2, y1);
    p[2] = Point(x2, y2);
    p[3] = Point(x1, y2);
    // 矩形在圆内，采用简单判定 4 个顶点是否有在圆内的
    for(int i = 0; i < 4; ++i) {
      if(Length(p[i] - c) < r)
        return true;
    }
    double min_dist = 1e10, max_dist = -1e10;
    for(int i = 0; i < 4; ++i) {
      double L, R;
      DistanceToSegment(c, p[i], p[(i + 1) % 4], L, R);
      min_dist = min(min_dist, L);
      max_dist = max(max_dist, R);
      cout << L << " " << R << endl;
    }
    if(dcmp(min_dist - r) > 0 || dcmp(r - max_dist) > 0)
      return false;
    return true;
  }
};
