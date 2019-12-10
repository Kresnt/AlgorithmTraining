class Solution {
 public:
  int cal(vector<int>&nums, int x) {
    int ans(0);
    for(auto i : nums) {
      ans += (i+x-1) / x;
    }
    return ans;
  }
  int smallestDivisor(vector<int>& nums, int threshold) {
    int first = 1, middle, half, len = *max_element(nums.begin(), nums.end());
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      if(cal(nums, middle) > threshold) {
        first = middle + 1;
        len = len - half - 1;
      } else
        len = half;
    }
    return first;
  }

};