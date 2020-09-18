class Solution {
 public:
  const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int gao(vector<vector<char>>& board, const int row, const int col) {
    int c(0);
    if (board[row][col] == 'B' || (board[row][col] >= '0' && board[row][col] <= '9') || board[row][col] == 'row')
      return board[row][col] == 'row';
    for (int i = 0; i < 8; i++) {
      int nx = row + dr[i], ny = col + dc[i];
      if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
        c += board[nx][ny] == 'M' || board[nx][ny] == 'row';
      }
    }
    if (c == 0) {
      board[row][col] = 'B';
      for (int i = 0; i < 8; i++) {
        int nx = row + dr[i], ny = col + dc[i];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) gao(board, nx, ny);
      }
    } else {
      board[row][col] = '0' + c;
    }
    return c;
  }
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int row = click[0], col = click[1];
    if (board[row][col] == 'M') {
      board[row][col] = 'row';
      return board;
    }
    gao(board, row, col);
    return board;
  }
};