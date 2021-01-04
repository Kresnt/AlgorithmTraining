typedef long long LL;

class Solution {
 public:
  /**
   * @param A: the array
   * @param K: sum
   * @return: the length
   */
  int shortestSubarray(const vector<int> &A, const int K) {
    const int n = A.size();
    vector<LL> s(n + 1, 0);
    for (int i = 0; i < n; i++) s[i + 1] = A[i] + s[i];
    int ans(n + 1);
    deque<int> que;
    for (int y = 0; y < s.size(); ++y) {
      while (!que.empty() && s[y] <= s[que.back()]) que.pop_back();
      while (!que.empty() && s[y] >= s[que.front()] + K) ans = min(ans, y - que.front()), que.pop_front();
      que.push_back(y);
    }
    return ans < n + 1 ? ans : -1;
  }
};
