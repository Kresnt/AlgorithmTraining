#pragma G++ optimize("O2")

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    const int n = nums.size();
    if(n == 0)
      return 0;
    int p = 0, q = 0;
    while(q < n) {
      nums[p++] = nums[q];
      while(q < n && nums[q] == nums[p - 1])
        q++;
    }
    return p;
  }
};
