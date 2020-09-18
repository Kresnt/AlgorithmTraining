typedef pair<int, int> P;

class Solution {
 public:
  int gao(const vector<string>& maze, P s, P t, map<pair<P, P>, int>&mem) {
    const int n = maze.size();
    const int m = maze[0].length();
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    if(mem.find({s, t}) != mem.end())
      return mem[ {s, t}];

    vector<vector<bool>>vis(n, vector<bool>(m, false));
    vector<vector<int>>dis(n, vector<int>(m, INT_MAX));
    queue<P>que;
    que.push(s);
    vis[s.first][s.second] = true, dis[s.first][s.second] = 0;
    while(!que.empty()) {
      P u = que.front();
      que.pop();
      if(u == t) {
        mem[ {s, t}] = mem[ {t, s}] = dis[u.first][u.second];
      }
      for(int i = 0; i < 4; ++i) {
        P v(u.first + dx[i], u.second + dy[i]);
        if(v.first >= 0 && v.first < n && v.second >= 0 && v.second < m && maze[v.first][v.second] != '#') {
          dis[v.first][v.second] = min(dis[v.first][v.second], dis[u.first][u.second] + 1);
          if(maze[v.first][v.second] != '.')
            mem[ {s, v}] = mem[ {v, s}] = dis[v.first][v.second];
          if(!vis[v.first][v.second]) {
            vis[v.first][v.second] = true;
            que.push(v);
          }
        }
      }
    }
    if(mem.find({s, t}) != mem.end())
      return mem[ {s, t}];
    else
      return -1;
  }

  int minimalSteps(vector<string>& maze) {
    const int n = maze.size();
    const int m = maze[0].length();
    P s, t;
    vector<P>g(2);
    vector<P>h;
    map<pair<P, P>, int>mem;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        if(maze[i][j] == 'S')
          g[0] = {i, j};
        else if(maze[i][j] == 'T')
          g[1] = {i, j};
        else if(maze[i][j] == 'M')
          g.push_back({i, j});
        else if(maze[i][j] == 'O')
          h.push_back({i, j});
    }
    vector<vector<int>> dis(g.size(), vector<int>(1 << g.size(), INT_MAX));
    vector<vector<int>>dist(g.size(), vector<int>(g.size(), INT_MAX));
    for(int i = 0; i < (int)g.size(); i++)
      for(int j = 0; j < i; j++) {
        if(i == 1 || j == 1) {
          dist[i][j] = gao(maze, g[i], g[j], mem);
          dist[i][j] = dist[j][i] = dist[i][j] == -1 ? INT_MAX : dist[i][j];
        } else
          for(P k : h) {
            int d1 = gao(maze, g[i], k, mem);
            if(d1 == -1)
              continue;
            int d2 = gao(maze, k, g[j], mem);
            if(d1 != -1 && d2 != -1 && dist[i][j] > d1 + d2)
              dist[i][j] = dist[j][i] = d1 + d2;
          }
      }
    dis[0][1] = 0;/// [addr][status]
    for(int i = 1; i < (1 << g.size()); i++) { /// status
      for(int j = 0; j < (int)g.size(); j++) {
        if(!(i & (1 << j)))
          continue;
        for(int k = 0; k < (int)g.size(); k++) {
          if(!(i & (1 << k)) || k == j)
            continue;
          if(dist[k][j] == INT_MAX || dis[k][i ^ (1 << j)] == INT_MAX)
            continue;
          dis[j][i] = min(dis[j][i], dis[k][i ^ (1 << j)] + dist[k][j]);
        }
      }
    }
    return dis[1][(1 << g.size()) - 1] == INT_MAX ? -1 : dis[1][(1 << g.size()) - 1];
  }
};
