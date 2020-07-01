class Solution {
 public:
  vector<int> singleNumbers(vector<int>& nums) {
    const int n = nums.size();
    int p(0), q(n - 1);
    int nums_x(0);
    for(int i = 0; i < n; ++i) {
      nums_x ^= nums[i];
    }
    nums_x = nums_x & (-nums_x);

    int low(0), high(n - 1);
    while(low < high) {
      while(low < high && (nums[low]&nums_x))
        low++;
      while(low < high && !(nums[high]&nums_x))
        high--;
      if(low < high)
        swap(nums[low], nums[high]);
    }
    vector<int>ans(2);
    for(int i = 0; i < low; ++i) {
      ans[0] ^= nums[i];
    }
    for(int i = high; i < n; ++i) {
      ans[1] ^= nums[i];
    }
    return ans;
  }
};
