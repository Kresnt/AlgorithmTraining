class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >que;
    vector<int>ptr(n, 0);
    for(int i = 0; i < n; ++i)
      que.push(make_pair(matrix[i][0], i));
    while(--k) {
      auto p = que.top();
      que.pop();
      ptr[p.second]++;
      if(ptr[p.second] < n) {
        int q = matrix[p.second][ptr[p.second]];
        que.push(make_pair(q, p.second));
      }
    }
    return que.top().first;
  }
};
