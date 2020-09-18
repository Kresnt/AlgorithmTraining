class Solution {
 public:
  void gao(vector<int>&nums, int &ans) {
    for(int i = 0, j, k; i < nums.size() - 1; i++) {
      if(nums[i] < nums.size() - 1 - i) {
        j = i + 1;
        while(j < nums.size() && nums[j] < nums.size() - 1 - i)
          j++;
        if(j == nums.size())
          return;
        for(k = j; k > i; k--)
          swap(nums[k], nums[k - 1]), ans++;
      }
    }
  }

  int minSwaps(vector<vector<int>>& grid) {
    int ans(0);
    vector<int>nums(grid.size(), 0);
    for(int i = 0; i < nums.size(); i++) {
      for(int j = grid[i].size() - 1; j >= 0; j--) {
        if(grid[i][j] == 0)
          nums[i]++;
        else
          break;
      }
    }
    for(int i = 0; i <= nums.size(); i++) {
      bool flag = true;
      for(int j = 0; j < nums.size(); j++)
        flag &= nums[j] >= nums.size() - 1 - j;
      if(flag)
        return ans;
      gao(nums, ans);
    }
    return -1;
  }
};
