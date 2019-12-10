class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if(nums.size() == 0)
      return -1;
    int first = 0, len = nums.size();
    if(nums[first] < nums[len - 1]) {
      first = (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
      return (first < nums.size() && nums[first] == target) ? first : -1;
    }

    int middle, half;
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      if(nums[middle] >= nums[0])
        first = middle + 1, len = len - half - 1;
      else
        len = half;
    }
    if(nums[0] < target) {
      len = first;
      first = 0;
      while(len > 0) {
        half = len >> 1;
        middle = first + half;
        if(nums[middle] < target)
          first = middle + 1, len = len - half - 1;
        else
          len = half;
      }
    } else if(nums[0] > target) {
      cout << first << " ";
      len = nums.size() - first;
      while(len > 0) {
        half = len >> 1;
        middle = first + half;
        if(nums[middle] < target)
          first = middle + 1, len = len - half - 1;
        else
          len = half;
      }
      cout << first << " ";
    } else
      return 0;
    return (first < nums.size() && nums[first] == target) ? first : -1;
  }
};
