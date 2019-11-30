#define PB push_back
class Solution {
public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    vector<vector<int>> ans;
    for(vector<int> interval : intervals){
      if(interval[0] >= toBeRemoved[1] || (interval[1] <= toBeRemoved[0])){
        ans.PB(interval);
      }else if(toBeRemoved[0] < interval[0]){
        if(toBeRemoved[1] >= interval[1]) continue;
        else if(toBeRemoved[1] < interval[1]) ans.PB(vector<int>{toBeRemoved[1],interval[1]});
      }else if(toBeRemoved[0] < interval[1]){
        if(toBeRemoved[1] < interval[1]) {
          if(interval[0]!=toBeRemoved[0])ans.PB(vector<int>{interval[0],toBeRemoved[0]});
          if(toBeRemoved[1]!=interval[1])ans.PB(vector<int>{toBeRemoved[1],interval[1]});
        }
        else if(toBeRemoved[1] >= interval[1]) {
          if(interval[0]!=toBeRemoved[0])ans.PB(vector<int>{interval[0],toBeRemoved[0]});
        }
      }
    }
    return ans;
  }
};