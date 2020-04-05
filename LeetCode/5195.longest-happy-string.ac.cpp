class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    pair<int, char> q[3] = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    string s("");
    for(int n;;) {
      sort(q, q + 3, greater<pair<int, char> >());
      if(q[0].first == 0)
        break;
      n = s.length();
      if(n >= 2 && q[0].second == s[n - 1] && q[0].second == s[n - 2]) {
        if(q[1].first == 0)
          return s;
        else {
          s += q[1].second;
          q[1].first --;
        }
      } else {
        s += q[0].second;
        q[0].first --;
      }
    }
    return s;
  }
};
