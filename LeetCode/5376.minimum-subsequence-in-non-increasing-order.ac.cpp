class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    int s = accumulate(nums.begin(), nums.end(), 0);
    int ps = 0;
    vector<int>ans;
    for(int i = 0; i < n; ++i) {
      ps += nums[i];
      ans.push_back(nums[i]);
      if(ps > s - ps)
        return ans;
    }
    return ans;
  }
};
