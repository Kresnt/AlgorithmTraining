class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int>ans(n, 1);
    // for(int i = 0,l = 1;i < n;++i){
    //   ans[i] *= l;
    //   l*= nums[i];
    // }
    // for(int i = n-1,r;i >= 0;--i){
    //   ans[i]*=r;
    //   r *= nums[i];
    // }
    for(int i = 0, j = n - 1, l = 1, r = 1; i < n && j >= 0; i++, j--) {
      ans[i] *= l, ans[j] *= r;
      l *= nums[i], r *= nums[j];
    }
    return ans;
  }
};
