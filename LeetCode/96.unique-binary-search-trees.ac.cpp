class Solution {
 public:
  int numTrees(int n) {
    // wiki:C(2n,n)/n+1 = 2n! / ( n£¡ (n+1)! )
    // how to get this ? C_{i+1} = 2*(2*i+1)/(i+2) C_{i}
    unsigned long long ans = 1;
    for(int i = 0; i < n; ++i)
      ans = 2 * (2 * i + 1) * ans / (i + 2);
    return ans;
  }
};
