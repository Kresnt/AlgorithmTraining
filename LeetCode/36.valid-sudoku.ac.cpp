class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; ++i) {
      bool vis[9] = {false};
      for(int j = 0; j < 9; ++j) {
        if(board[i][j] == '.') {
          continue;
        }
        if(vis[board[i][j] - '1'])
          return false;
        vis[board[i][j] - '1'] = true;
      }

      memset(vis, false, sizeof(vis));
      for(int j = 0; j < 9; ++j) {
        if(board[j][i] == '.') {
          continue;
        }
        if(vis[board[j][i] - '1'])
          return false;
        vis[board[j][i] - '1'] = true;
      }
    }
    cout << "check square" << endl;
    for(int i = 0; i < 9; i += 3) {
      for(int j  = 0; j < 9; j += 3)
        if(!check_square(board, i, j))
          return false;
    }
    return true;
  }

  bool check_square(vector<vector<char>>& board, int x, int y)const {
    bool vis[9] = {false};
    for(int i = x; i < x + 3; i++)
      for(int j = y; j < y + 3; j++) {
        if(board[i][j] != '.') {
          if(vis[board[i][j] - '1'])
            return false;
          vis[board[i][j] - '1'] = true;
        }
      }
    return true;
  }
};
