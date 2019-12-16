class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    int n = arr.size(), val = arr[0];
    pair<int, int>ans({0, 0});
    for(int i = 0, c = 0; i < n; ++i) {
      if(arr[i] == val)
        c++, ans = max(ans, make_pair(c, val));
      else
        c = 1, val = arr[i];
    }
    return ans.second;
  }
};
