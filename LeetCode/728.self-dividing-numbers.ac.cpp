class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int>ans;
    for(;left <= right;left++)
      if(is_selfDividingNumber(left))
        ans.push_back(left);
    return ans;
  }

  bool is_selfDividingNumber(const int x) {
    for(int  i = x,div; i; i = i / 10) {
      div = i % 10;
      if(div == 0 || x % div)
        return false;
    }
    return true;
  }
};
