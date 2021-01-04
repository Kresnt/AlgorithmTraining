class Solution {
 public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> pos;
    for (int i = 0; i < target.size(); i++) pos[target[i]] = i;
    vector<int> a;
    for (int x : arr) {
      if (pos.count(x)) a.emplace_back(pos[x]);
    }
    int len = 0;
    vector<int> q(a.size() + 1);
    for (int i = 0; i < a.size(); i++) {
      int l = 0, r = len, mid;
      while (l < r) {
        mid = l + r + 1 >> 1;
        if (q[mid] < a[i])
          l = mid;
        else
          r = mid - 1;
      }
      len = max(len, r + 1);
      q[r + 1] = a[i];
    }
    return target.size() - len;
  }
};