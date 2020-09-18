#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 7;
const int inf = 0x3f3f3f3f;

class Solution {
  struct point {
    int x, y, id;
    bool operator<(const point &a) const { return a.x == x ? y < a.y : x < a.x; }
  } p[maxn];  //按x从小到大排序，再按y-x离散

  struct node {
    int u, v, w;
    bool operator<(const node &a) const { return w < a.w; }
  } edge[maxn << 2];

  struct Bit {  //树状数组维护区间最小值
    int pos, w;
    void init() { pos = -1, w = inf; }
  } bit[maxn];

  int fa[maxn], a[maxn], b[maxn];  //数组a,b用于离散化，求得 在y轴向右45度的所有点
  int n, m, cnt;

  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void add(int u, int v, int w) { edge[++cnt].u = u, edge[cnt].v = v, edge[cnt].w = w; }
  int lowbit(int x) { return x & (-x); }
  int dist(point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
  int query(int x, int m) {  //查询区间p[i].x+p[i].y最小值
    int minx = inf, pos = -1;
    for (int i = x; i <= m; i += lowbit(i)) {
      if (minx > bit[i].w) {
        minx = bit[i].w;
        pos = bit[i].pos;
      }
    }
    return pos;
  }
  void update(int x, int y, int pos) {  //维护区间p[i].x+p[i].y最小值
    for (int i = x; i >= 1; i -= lowbit(i)) {
      if (y < bit[i].w) {
        bit[i].w = y;
        bit[i].pos = pos;
      }
    }
  }
  int Kruskal() {
    int ans(0);
    sort(edge + 1, edge + cnt + 1);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= cnt; i++) {
      if (find(edge[i].u) != find(edge[i].v)) {
        fa[find(edge[i].u)] = find(edge[i].v);
        ans += edge[i].w;
      }
    }
    return ans;
  }

 public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    n = points.size();
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      p[i].x = points[i - 1][0], p[i].y = points[i - 1][1];
      p[i].id = i;
    }
    for (int j = 0; j < 4; j++) {
      if (j == 1 || j == 3)
        for (int i = 1; i <= n; i++) swap(p[i].x, p[i].y);
      else if (j == 2)
        for (int i = 1; i <= n; i++) p[i].x = -p[i].x;
      sort(p + 1, p + n + 1);
      for (int i = 1; i <= n; i++) a[i] = b[i] = p[i].y - p[i].x;
      sort(b + 1, b + n + 1);
      m = unique(b + 1, b + n + 1) - b;  //去重
      for (int i = 1; i <= m; i++) bit[i].init();
      for (int i = n; i >= 1; i--) {
        //只能从x大的 开始遍历,图像从右往左遍历，才能查询和维护R1,R2,R3,R4区域最小距离点
        int x = lower_bound(b + 1, b + m + 1, a[i]) - b + 1;  //从y轴向右45度的区域寻找，即b.y-b.x>a.y-a.x
        for (int xxx = 10; xxx > 0; x++, xxx--) {
          int pos = query(x, m);  //查找与点p[i]最近的点（y轴向右45度的区域）
          if (pos != -1)          //查询到就连边
            add(p[i].id, p[pos].id, dist(p[i], p[pos]));
          update(x, p[i].x + p[i].y, i);  //维护区间最小值
        }
      }
    }
    return Kruskal();
  }
};

int main() {
  vector<vector<int>> input = {{3, 3},     {1, -1},  {-8, -14}, {-3, 18}, {-14, 9},  {17, 18},  {-16, 7},
                               {-18, -19}, {3, 9},   {0, 12},   {-4, -8}, {-8, -13}, {-3, -12}, {16, 15},
                               {10, -4},   {-3, -6}, {18, -1},  {-7, 9},  {-14, 10}, {8, 6}};
  Solution *sol = new Solution();
  // cout << sol->minCostConnectPoints(input) << endl;
  input = {{-17, 14}, {-6, 18}, {14, -16}, {9, 4}, {-9, -17}, {7, 8}, {-12, 20}, {-15, 15}, {-12, 19}, {-19, -20}};
  cout << sol->minCostConnectPoints(input) << endl;
}