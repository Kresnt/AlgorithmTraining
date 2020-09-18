class Solution {
 public:
  int minNumberOperations(vector<int>& target) {
    stack<int>sk;
    int ans(0);
    sk.push(0);
    for(int i = 0; i < target.size(); i++) {
      while(sk.top() > target[i]) {
        sk.pop();
        if(sk.top() < target[i])
          sk.push(target[i]);
      }
      if(sk.top() < target[i]) {
        ans += target[i] - sk.top();
        sk.push(target[i]);
      }
    }
    return ans;
  }
};
