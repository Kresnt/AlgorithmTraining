class Solution {
 public:
  int sumNums(int n) {
    n && (return n + sumNums(n - 1));
    return 0;
  }
};
