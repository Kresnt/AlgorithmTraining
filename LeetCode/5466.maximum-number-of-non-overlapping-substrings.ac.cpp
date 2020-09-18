typedef pair<int, int>PII;

class Solution {
 public:
  vector<string> maxNumOfSubstrings(string s) {
    if(s.length() == 0)
      return {};
    vector<PII>st;
    vector<int>first_pos(26, -1), last_pos(26, -1);
    for(int i = 0; i < 26; ++i) {
      first_pos[i] = s.find_first_of('a' + i);
      last_pos[i] = s.find_last_of('a' + i);
    }
    for(int i = 0; i < 26; ++i) {
      size_t b = s.find_first_of('a' + i);
      size_t e = s.find_last_of('a' + i);
      if(b == string::npos)
        continue;
      for(bool redo = true; redo;) {
        redo = false;
        for(int j = b; j <= e; j++)
          if(e < last_pos[s[j] - 'a'])
            e = last_pos[s[j] - 'a'];
          else if(b > first_pos[s[j] - 'a'])
            b = first_pos[s[j] - 'a'], redo = true;
      }
      st.push_back({e - b + 1, b});
    }
    sort(st.begin(), st.end());
    vector<bool>vis(s.length(), false);
    vector<string>ans;
    for(PII p : st) {
      bool v = false;
      for(int j = p.second; j < p.second + p.first; j++) {
        if(vis[j]) {
          v = true;
          break;
        }
      }
      if(v)
        continue;
      ans.push_back(s.substr(p.second, p.first));
      for(int j = p.second; j < p.second + p.first; j++)
        vis[j] = true;
    }
    return ans;
  }
};
