#pragma G++ optimize("O2")

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    const int n = nums.size();
    if(n == 0)
      return 0;
    int p = 0;
    for(int i = 0; i < n; ++i) {
      if(nums[i] != val)
        nums[p++] = nums[i];
    }
    return p;
  }
};
