class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int> >ans;
    sort(intervals.begin(), intervals.end());
    for(vector<int>p : intervals) {
      if(!ans.size()) {
        ans.push_back(p);
      } else {
        vector<int> &q = ans.back();
        if(p[0] > q[1])
          ans.push_back(p);
        else
          q[1] = max(q[1], p[1]);
      }
    }
    return ans;
  }
};
