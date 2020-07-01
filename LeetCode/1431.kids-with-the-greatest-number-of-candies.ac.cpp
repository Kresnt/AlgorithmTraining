class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    const int n = candies.size();
    const int m = *max_element(candies.begin(), candies.end());
    vector<bool>ans(n);
    for(int i = 0; i < n; ++i)
      ans[i] = candies[i] + extraCandies >= m;
    return ans;
  }
};
