#pragma G++ optimize("O2")

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 1e5;
    for(int a = 0; a < n; a++) {
      for(int b = a + 1, c = n - 1, s; b < n; ++b) {
        s = nums[a] + nums[b] + nums[c];
        while(s > target && c > b) {
          if(abs(s - target) < abs(ans - target))
            ans = s;
          c--;
          s = nums[a] + nums[b] + nums[c];
        }
        if(c > b && abs(s - target) < abs(ans - target))
          ans = s;
      }
    }
    return ans;
  }
};
