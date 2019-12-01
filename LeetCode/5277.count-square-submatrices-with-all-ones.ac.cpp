class Solution {
 public:
  int n, m;
  int countSquares(vector<vector<int>>& matrix) {
    n = matrix.size(), m = matrix[0].size();
    int ans(0);
    for(int i = 1, c; i <= min(n, m); ++i) {
      c = count(matrix, i);
      ans += c;
      if(!c)
        break;
    }
    return ans;
  }
  int count(vector<vector<int> >&matrix, int edgeLen) {
    int ans(0);
    for(int i = 0; i < n - edgeLen + 1; ++i) {
      for(int j = 0; j < m - edgeLen + 1; ++j)
        if(isSquareAllOne(matrix, i, j, edgeLen))
          ans++;
    }
    return ans;
  }

  bool isSquareAllOne(vector<vector<int>>&matrix, int x, int y, int edgeLen) {
    for(int i = 0; i < edgeLen; ++i) {
      for(int j = 0; j < edgeLen; ++j)
        if(!matrix[x + i][y + j])
          return false;
    }
    return true;
  }

};
