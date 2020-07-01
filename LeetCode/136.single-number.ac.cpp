class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans(0);
    for(int i = 0, sz = nums.size(); i < sz; ++i)
      ans ^= nums[i];
    return ans;
  }
};
