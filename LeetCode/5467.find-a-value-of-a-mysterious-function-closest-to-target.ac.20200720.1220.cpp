class Solution {
 public:
  int closestToTarget(vector<int>& arr, int target) {
    set<int>a[2];
    a[0].insert(INT_MAX);
    int ans(INT_MAX);
    for(int i = 0; i < arr.size(); ++i) {
      a[(i + 1) % 2].clear();
      for(int j : a[i % 2]) {
        a[(i + 1) % 2].insert(j & arr[i]);
        ans = min(ans, abs((j & arr[i]) - target));
      }
      a[(i + 1) % 2].insert(arr[i]);
      ans = min(ans, abs(arr[i] - target));
      a[i % 2].clear();
    }
    return ans;
  }
};
