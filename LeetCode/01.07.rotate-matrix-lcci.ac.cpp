class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    if(n <= 1)
      return;
    for(int i = 0; i < n; ++i) {
      for(int j = i; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for(int i = 0; (i << 1) < n; ++i) {
      for(int j = 0; j < n; ++j) {
        swap(matrix[j][i], matrix[j][n - i - 1]);
      }
    }

  }
};
