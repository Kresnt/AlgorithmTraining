class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    const int n = tasks.size();
    sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
      if (a[1] - a[0] != b[1] - b[0]) return a[1] - a[0] < b[1] - b[0];
      return a[1] < b[1];
    });

    int ans(0), d(0);
    for (int i = 0; i < n; ++i) {
      ans += tasks[i][0];
      if (ans + d < tasks[i][1]) d += tasks[i][1] - ans;
    }
    return ans + d;
  }
};