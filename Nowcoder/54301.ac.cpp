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

int p[maxn], q[maxn];
int ans, cnt, n, k;

int qpow(int x, int y, const int c = MOD) {
  int ret(1);
  while(y) {
    if(y & 1)
      ret = 1ll * ret * x % c;
    x = 1ll * x * x % c, y >>= 1;
  }
  return ret;
}

void DFS(int x, int d, int phi) {
  if(x == cnt) {
    ans = (ans + 1ll * phi * qpow(k, n / d)) % MOD;
    return;
  }
  DFS(x + 1, d, phi);
  d *= p[x];
  phi *= p[x] - 1;
  for(int i = 1; i <= q[x]; ++i)
    DFS(x + 1, d, phi), d *= p[x], phi *= p[x];
}

inline void factorization(int m) {
  cnt = 0;
  for(int i = 2; i * i <= m; ++i)
    if(!(m % i)) {
      p[cnt] = i;
      q[cnt] = 0;
      while(!(m % i))
        ++q[cnt], m /= i;
      cnt++;
    }
  if(m > 1)
    p[cnt] = m, q[cnt] = 1, ++cnt;
}

void solve() {
  /*********** start your code here. ************/
  cin >> n >> k;
  k = 1ll * k * (k + 1) / 2 % MOD;
  factorization(n);
  ans = 0;
  DFS(0, 1, 1);
  ans = 1ll * ans * qpow(n, MOD - 2) % MOD;
  cout << ans << "\n";
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