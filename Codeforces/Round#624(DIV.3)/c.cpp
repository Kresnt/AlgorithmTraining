#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <bitset>

using std::priority_queue;
using std::bitset;
using std::string;
using std::replace;
using std::vector;
using std::greater;
using std::sort;
using std::swap;
using std::cin;
using std::cout;
using std::endl;
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

const int maxn = 1e2 + 7;
const LL MOD = 1e9 + 7;



void solve() {
  /*********** start your code here. ************/
  LL c[26] = {0};
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int p[m + 1];
  REP(i, m) cin >> p[i];
  sort(p, p + m);
  p[m] = n;
  for(int i = 0, j = 0; i < n; ++i) {
    while(i == p[j])
      j++;
    c[s[i] - 'a'] += m - j + 1;
  }
  REP(i, 26) cout << c[i] << (i == 25 ? '\n' : ' ');
}

void init() {
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T(1);
  std::cin >> T;
  init();
  while(T--)
    solve();
  return 0;
}
