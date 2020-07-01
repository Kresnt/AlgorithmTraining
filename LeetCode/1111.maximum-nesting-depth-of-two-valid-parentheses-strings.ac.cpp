class Solution {
 public:
  vector<int> maxDepthAfterSplit(string seq) {
    const int n = seq.length();
    vector<int> ans(n);
    int c = -1;
    for(int i = 0; i < n; ++i) {
      if(seq[i] == '(')
        c++, ans[i] = c % 2;
      else
        ans[i] = c % 2, c--;
    }
    return ans;
  }
};