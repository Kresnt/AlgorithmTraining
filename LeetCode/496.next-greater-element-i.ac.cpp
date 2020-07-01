#pragma G++ optimize("O2")

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums2.size();
    stack<int>s;
    map<int, int>g;
    for(int i = n - 1; i >= 0; i--) {
      while(!s.empty() && nums2[i] > s.top())
        s.pop();
      if(s.empty())
        g[nums2[i]] = -1;
      else
        g[nums2[i]] = s.top();
      s.push(nums2[i]);
    }
    vector<int>ans(nums1.size());
    for(int i = 0; i < nums1.size(); i++)
      ans[i] = g[nums1[i]];
    return ans;

  }
};
