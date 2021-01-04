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

const int maxn = 2e3 + 7;
const int MOD = 19260817;

void solve() {
  /*********** start your code here. ************/
  int n,d,l;
  cin >>n >> d >>l;
  rep(i,n) cin >> cor[i].x ;

}

void init() {
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  init();
  int T(1);
  std::cin >> T;
  while(T--)
    solve();
  return 0;
}
