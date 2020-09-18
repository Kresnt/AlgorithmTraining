#pragma G++ optimize("O2")

class Solution {
 public:
  inline int distance(string&a, string &b)const {
    int ans(0);
    for(int i = 0; i < (int)a.length(); i++)
      ans += (a[i] != b[i]);
    return ans;
  }

  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    sort(wordList.begin(), wordList.end());
    wordList.erase(unique(wordList.begin(), wordList.end()), wordList.end());
    int n = wordList.size();
    vector<vector<int>>g(n);
    for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
        if(distance(wordList[i], wordList[j]) == 1) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }

    int src = lower_bound(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
    int dest = lower_bound(wordList.begin(), wordList.end(), endWord) - wordList.begin();
    if(wordList[dest] != endWord) {
      return {};
    }
    vector<vector<int>>ans;
    queue<vector<int>>que;
    vector<int>cost(n, INT_MAX);
    que.push({src});
    cost[src] = 0;
    while(!que.empty()) {
      vector<int>path = que.front();
      que.pop();

      int u = path.back();
      if(ans.size() && path.size() > ans[0].size())
        continue;
      if(u == dest) {
        if(ans.size() == 0 || path.size() == ans[0].size())
          ans.push_back(path);
        continue;
      }
      int new_path_len = path.size() + 1;
      for(int v : g[u]) {
        bool visited(false);
        for(int w : path) if(w == v) visited = true;
        if(visited || cost[v] < new_path_len)
          continue;

        path.push_back(v);
        if(cost[v] > new_path_len + 1)
          cost[v] = new_path_len;
        que.push(path);
        path.pop_back();
      }
    }
    sort(ans.begin(),ans.end());
    vector<vector<string>>ret;
    for(vector<int>path : ans) {
      vector<string>q;
      for(int i : path)
        q.push_back(wordList[i]);
      ret.push_back(q);
    }
    return ret;
  }
};
