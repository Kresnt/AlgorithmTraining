class Solution {
 public:
  bool isValid(string s) {
    stack<char>stk;
    const string par = "{[()]}";
    for(char ch : s) {
      for(int j = 0; j < par.length(); j++)
        if(ch == par[j]) {
          if(j < par.length() / 2)
            stk.push(ch);
          else if(!stk.empty() && stk.top() == par[par.length() - 1 - j])
            stk.pop();
          else
            return false;
          break;
        }

    }
    return stk.empty();
  }
};
