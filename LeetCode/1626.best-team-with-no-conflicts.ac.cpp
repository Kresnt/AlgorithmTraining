typedef pair<int, int> PII;

class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    const int n = scores.size();
    vector<PII> a(n);
    for (int i = 0; i < n; ++i) a[i].first = ages[i], a[i].second = scores[i];
    sort(a.begin(), a.end());
    vector<int> d(n, 0);
    int ans(INT_MIN);
    for (int i = 0; i < n; ++i) {
      d[i] = a[i].second;
      for (int j = 0; j < i; j++) {
        if (a[i].second >= a[j].second) d[i] = max(d[i], d[j] + a[i].second);
      }
      ans = max(ans, d[i]);
    }
    return ans;
  }
};