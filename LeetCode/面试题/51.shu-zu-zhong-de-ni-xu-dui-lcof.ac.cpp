class Solution {
 public:

  inline int lowbit(int x) {return x & (-x);}

  int reversePairs(vector<int>& nums) {
    const int n = nums.size();
    vector<int> de(nums);
    vector<int>tree(n + 1, 0);
    int ans(0);

    sort(de.begin(), de.end());
    de.resize(unique(de.begin(), de.end()) - de.begin());
    for(int i : de)
      cout << i << " ";
    cout << endl;
    for(int i = n - 1, x, k; i >= 0; --i) {
      x = lower_bound(de.begin(), de.end(), nums[i]) - de.begin() + 1;
      k = x - 1;
      while(k > 0) {
        ans += tree[k];
        k -= lowbit(k);
      }
      k = x;
      while(k <= n) {
        tree[k] += 1;
        k += lowbit(k);
      }
    }
    return ans;
  }
};
