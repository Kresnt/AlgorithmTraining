class Solution {
 public:
  int numRookCaptures(vector<vector<char> >& board) {
    const int n = board.size();
    const int m = board[0].size();
    int x, y, ans(0);
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        if(board[i][j] == 'R') {
          x = i, y = j;
          break;
        }
    for(int i = x; i >= 0; --i) {
      if(board[i][y] != '.' && board[i][y] != 'R') {
        ans += (board[i][y] == 'p' ? 1 : 0);
        break;
      }
    }
    for(int i = x; i < n; ++i) {
      if(board[i][y] != '.' && board[i][y] != 'R') {
        ans += (board[i][y] == 'p' ? 1 : 0);
        break;
      }
    }
    for(int i = y; i >= 0; --i) {
      if(board[x][i] != '.' && board[x][i] != 'R') {
        ans += (board[x][i] == 'p' ? 1 : 0);
        break;
      }
    }

    for(int i = y; i < m; ++i) {
      if(board[x][i] != '.' && board[x][i] != 'R') {
        ans += (board[x][i] == 'p' ? 1 : 0);
        break;
      }
    }
    return ans;
  }
};
