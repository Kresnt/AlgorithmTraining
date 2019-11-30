#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize(2)
 
#include <bits/stdc++.h>
#include <bitset>
 
using std::bitset;
using std::string;
using std::replace;
using std::vector;
using std::sort;
using std::cin;
using std::cout;
using std::map;
using std::min;
using std::max;
 
#define REP(i,n) for(int i=0;i<int(n);++i)
#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define DWN(i,b,a) for(int i=int(b);i>=int(a);--i)
 
/// type define
typedef double DB;
typedef long long LL;
typedef std::vector<int>VI;
typedef std::vector<LL>VLL;
typedef std::pair<int, int>PII;
typedef std::pair<LL, LL>PLL;
typedef std::vector<PII>VPII;
typedef std::vector<PLL>VPLL;
 
/// const
static const double eps = 1e-8;
static const double pi = acos(-1.0);
static const int inf = 0x3f3f3f3f;
static const LL INF = 0x3f3f3f3f3f3f3f3f;
 
/// common statement
#define PB push_back
#define MP std::make_pair
#define fi first
#define se second
 
/****************************************************************/
 
const int maxn = 8e2 + 7;
const LL MOD = 1e9 + 7;
 
 
VLL g1(maxn*maxn), g2(maxn*maxn);
LL a[maxn], p[maxn][maxn];
void solve() {
  /*********** start your code here. ************/
  int n, m, k, y;
  cin >> n >> m >> k >> y;
  REP(i, n) cin >> a[i];
  REP(i, n)REP(j, m) cin >> p[i][j + 1];
  VLL *last = &g1, *cur = &g2;
  REP(i, k + 1) (*cur)[i] = INF;
  (*cur)[0] = 0;
  REP(i, n) {
    swap(cur, last);
    //REP(j, k + 1)cout << (*last)[j] << " ";cout << "\n";
    REP(j, k + 1)(*cur)[j] = (*last)[j];
    for(int j = 0; j <= min(m, k); ++j) {
      LL cost = p[i][j] + (j < y ? a[i] * j : 0);
      for(int icur = j; icur <= k; ++icur) {
        (*cur)[icur] = min((*cur)[icur], (*last)[icur - j] + cost);
      }
    }
  }
  cout << (*cur)[k] << "\n";
}
 
void init() {
 
}
 
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T(1);
  //std::cin >> T;
  init();
  while(T--)
    solve();
  return 0;
}