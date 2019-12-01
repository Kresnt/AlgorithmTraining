class Solution {
 public:

  int run(int g[3][3], vector<int>&move, int val) {
    g[move[0]][move[1]] = val;
    int t = 0, ans = 0;
    for(int i = move[0]; i < 3; ++i) {
      if(g[i][move[1]] == val)
        t++;
      else
        break;
    }
    for(int i = move[0] - 1; i >= 0; --i) {
      if(g[i][move[1]] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    for(int i = move[1]; i < 3; ++i) {
      if(g[move[0]][i] == val)
        t++;
      else
        break;
    }
    for(int i = move[1] - 1; i >= 0; --i) {
      if(g[move[0]][i] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    for(int i = 0; i + move[0] < 3 && i + move[1] < 3; ++i) {
      if(g[i + move[0]][i + move[1]] == val)
        t++;
      else
        break;
    }
    for(int i = -1; i + move[0] >= 0 && i + move[1] >= 0; --i) {
      if(g[i + move[0]][i + move[1]] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    for(int i = 0; i + move[0] < 3 && move[1] - i >= 0; ++i) {
      if(g[i + move[0]][-i + move[1]] == val)
        t++;
      else
        break;
    }
    for(int i = -1; i + move[0] >= 0 && move[1] - i < 3 ; --i) {
      if(g[i + move[0]][-i + move[1]] == val)
        t++;
      else
        break;
    }
    ans = max(ans, t);
    t = 0;

    return ans;
  }
  bool finished(int g[3][3]) {
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        if(g[i][j] == 0)
          return false;
    return true;
  }
  string tictactoe(vector<vector<int>>& moves) {
    int g[3][3];
    memset(g, 0, sizeof(g));
    for(int i = 0, n = moves.size(); i < n; ++i) {
      if(run(g, moves[i], i % 2 + 1) > 2)
        return (i & 1) ?  string("B") : string("A");
    }
    return finished(g) ? string("Draw") : string("Pending");
  }
};
