class Solution {
public:
  int findDuplicate(vector<int>& nums) const{
    int len = nums.size() - 1;
    int first = 1, half, mid, c;
    while(len > 0) {
      half = len >> 1;
      mid = first + half;
      c = 0;
      for(int i : nums)
        c += i <= mid ? 1 : 0;
      if(c > mid)
        len = half;
      else {
        first = mid + 1;
        len = len - half - 1;
      }
    }
    return first;
  }
};
