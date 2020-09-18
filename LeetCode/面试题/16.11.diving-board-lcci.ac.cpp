class Solution {
 public:
  vector<int> divingBoard(int shorter, int longer, int k) {
    if(k == 0 )
      return {};
    set<int>s;
    for(int i = 0; i <= k; i++) {
      s.insert(shorter * i + longer * (k - i));
    }
    vector<int>ans(s.begin(), s.end());
    return ans;
  }
};
