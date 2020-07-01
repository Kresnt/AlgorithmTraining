class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    vector<int> stk;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for(int i = 0, cur, left, right; i < heights.size(); i++) {
      while(!stk.empty() && heights[stk.back()] > heights[i]) {
        cur = stk.back();
        stk.pop_back();
        left = stk.back() + 1;
        right = i - 1;
        ans = max(ans, (right - left + 1) * heights[cur]);
      }
      stk.push_back(i);
    }
    return ans;
  }
};
