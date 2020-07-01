#pragma G++ optimize("O2")

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int s(0), ans(INT_MIN);
    for(int i : nums) {
      s += i;
      if(s > ans)
        ans = s;
      if(s < 0)
        s = 0;
    }
    return ans;
  }
};
