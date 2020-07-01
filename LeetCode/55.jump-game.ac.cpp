class Solution {
 public:
  bool canJump(vector<int>& nums) {
    const int n = nums.size();
    if(n == 0 )
      return true;
    int l = 0, r = 0;
    bool flag = false;
    while(true) {
      flag = false;
      int tmp = r;
      for(int i = l, sz = min(r, n - 1); i <= sz; ++i) {
        if(r < nums[i] + i) {
          flag = true;
          r = nums[i] + i;
        }
      }
      l = tmp;
      if(!flag)
        break;
    }
    return r >= n - 1;
  }
};
