#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:

  Solution() {}
  vector<vector<int> >ans;
  vector<vector<string> > totalNQueens(int n) {
    ans.clear();
    DFS(0, n, vector<int> {});
    int ret = ans.size();
    return ret;
  }

  vector<string> trans(vector<int>&r) {
    const int n = r.size();
    vector<string>ret(n, string(n, '.'));
    for(int i = 0; i < n; ++i) {
      ret[i][r[i]] = 'Q';
    }
    return ret;
  }

  void DFS(int s, const int n, vector<int>v) {
    if(s == n) {
      ans.push_back(vector<int>(v));
      return;
    }
    for(int i = 0; i < n; ++i) {
      bool f = true;
      for(int j = 0; f && j < v.size(); j++) {
        if(v[j] == i || v[j] + s - j == i || v[j] - s + j == i) {
          f = false;
          break;
        }
      }
      if(f) {
        v.push_back(i);
        DFS(s + 1, n, v);
        v.pop_back();
      }
    }
  }
};

int main() {
  Solution sol;
  sol.totalNQueens(4);
}
