class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    const int n = points.size();
    if(n < 3)
      return n;
    int ans = 2;
    for(int i = 0 ; i < n; ++i) {
      int i_cnt = 1;
      for(int j = i + 1; j < n; ++j) {
        int cnt = 0;
        if(points[i] == points[j])
          i_cnt++;
        else {
          cnt++;
          vector<int>&a = points[i];
          vector<int>&c = points[j];
          long long  dx_2 = a[0] - c[0], dy_2 = a[1] - c[1];
          long long dx_1, dy_1;
          for(int k = j + 1; k < n; ++k) {
            vector<int>&b = points[k];
            dx_1 = a[0] - b[0], dy_1 = a[1] - b[1];

            if(dy_1 * dx_2 == dy_2 * dx_1)
              cnt++;
          }
        }
        ans = max(ans, i_cnt + cnt);
      }
    }
    return ans;
  }
};
