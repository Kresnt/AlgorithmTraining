#pragma G++ optimize("O2")

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    const int n = A.size();
    int ans(INT_MIN), q(-1);
    for(int i = n - 1; i >= 0; --i) {
      if(q != -1 && A[i] + i + A[q] - q > ans) {
        ans = (A[i] + i + A[q] - q);
      }
      if(q == -1 || A[i] - i >= A[q] - q)
        q = i;
    }
    return ans;
  }
};
