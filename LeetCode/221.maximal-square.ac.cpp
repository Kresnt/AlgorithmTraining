class Solution {
 public:
  int maximalSquare(vector<vector<char> >& matrix) {
    if(matrix.size() == 0)
      return 0;
    const int n = matrix.size();
    const int m = matrix[0].size();

    vector<vector<int> >a(n, vector<int>(m, 0)); // from left to right
    vector<vector<int> >b(n, vector<int>(m, 0)); // from up to down
    vector<vector<int> >c(n, vector<int>(m, 0));
    int ans(0);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        const char ch = matrix[i][j];
        a[i][j] = b[i][j] = c[i][j] = (ch == '1' ? 1 : 0);
        if(i && ch == '1')
          b[i][j] += b[i - 1][j];
        if(j && ch == '1')
          a[i][j] += a[i][j - 1];
        if(i && j && ch == '1')
          c[i][j] = min(min(a[i][j], b[i][j]), c[i - 1][j - 1] + 1);
        ans = max(ans, c[i][j]);
        //cout << c[i][j] << " ";
      }
      //cout << endl;
    }
    return ans * ans;
  }
};
