class Solution {
 public:
  bool isValid(string s) {
    stack<char>st;
    string brackets[] = {"()", "[]", "{}"};
    for(int i = 0, n = s.length(); i < n; ++i) {
      for(auto j : brackets) {
        if(s[i] == j[1]) {
          if(st.empty() || st.top() != j[0])
            return false;
          else
            st.pop();
          break;
        } else if(s[i] == j[0]) {
          st.push(s[i]);
          break;
        }
      }
    }
    return st.empty();
  }
};
