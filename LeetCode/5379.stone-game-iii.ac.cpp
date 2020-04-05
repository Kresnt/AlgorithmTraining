class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    const int n = stoneValue.size();
    vector<pair<int, int> >d(n, {0, 0});
    for(int i = n - 1; i >= 0; --i) {
      d[i] = make_pair(INT_MIN, INT_MIN);
      for(int j = i; j < n && j < i + 3; ++j) {
        int rs = accumulate(&stoneValue[i], &stoneValue[j + 1], 0);
        if(j + 1 < n)
          d[i] = max(make_pair(d[j + 1].second + rs, d[j + 1].first), d[i]);
        else
          d[i] = max(make_pair(rs, 0), d[i]);
      }
      //cout << i << " " << d[i].first << " " << d[i].second << endl;
    }
    int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
    return sum - d[0].first != d[0].first ? (sum - d[0].first > d[0].first ? "Bob" : "Alice") : "Tie";

  }
};
