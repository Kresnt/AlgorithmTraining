class Solution {
 public:
  int gao(vector<vector<int>>&d, int x, int y)const {
    int k = log2(y - x + 1);
    int ret = d[x][k] & d[y - (1 << k) + 1][k];
    return ret;
  }

  int closestToTarget(vector<int>& arr, int target) {
    int len = arr.size();
    vector<vector<int>>d(len, vector<int>(20));
    for(int i = 0; i < len; ++i)
      d[i][0] = arr[i];
    for(int j = 1; j <= log2(len); ++j) {
      for(int i = 0; i + (1 << j) - 1 < len; ++i) {
        d[i][j] = d[i][j - 1] & d[i + (1 << (j - 1))][j - 1];
      }
    }
    int ans(0x7ffffff);
    for(int i = 0; i < len; ++i) {
      if(i && arr[i] == arr[i - 1])
        continue;
      int l = i, r = len - 1, mid;
      if(gao(d, i, r) < target)
        while(l < r) {
          //cout<< l << " " << r<<endl;
          mid = (l + r) >> 1;
          if(gao(d, i, mid) > target)
            l = mid + 1;
          else
            r = mid;
        } else
        l = r;
      ans = min(ans, abs(gao(d, i, l) - target));
      if(l - 1 >= i)
        ans = min(ans, abs(gao(d, i, l - 1) - target));
    }
    return ans;
  }
};
