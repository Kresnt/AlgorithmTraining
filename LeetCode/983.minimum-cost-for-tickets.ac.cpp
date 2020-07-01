#pragma GCC optimize("O2")
#pragma G++ optimize("O2")

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    const int n = days.size();
    const int m = costs.size();
    int c[366] = {0};
    int p = 0;

    sort(days.begin(), days.end());
    c[0] = 0;
    for(int i = 1; i <= 365; ++i) {
      if(p < n && i == days[p]) {
        c[i] = c[i - 1] + costs[0];
        c[i] = min(c[i], (*min_element(c + max(0, i - 7), c + i + 1)) + costs[1]);
        c[i] = min(c[i], (*min_element(c + max(0, i - 30), c + i + 1)) + costs[2]);
        p++;
        //cout << i << " " << c[i] << endl;
      } else {
        c[i] = c[i - 1];
      }
    }
    return c[365];
  }
};
