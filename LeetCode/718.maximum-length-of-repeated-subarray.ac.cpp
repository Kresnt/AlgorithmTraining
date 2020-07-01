class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int ans(0);
    for(int i  = 1 - ((int)A.size()); i < (int)A.size(); ++i) {
      int c = 0;
      for(int j = 0; j < B.size() && i + j < (int)A.size(); ++j) {
        if(i + j >= 0 && A[i + j] == B[j]) {
          c++;
          if(ans < c) ans = c;
        } else {
          c = 0;
        }
      }
    }
    return ans;
  }
};
