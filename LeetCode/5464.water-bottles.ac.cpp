class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    long long ans(numBottles);
    while(numBottles >= numExchange) {
      long long x = numBottles / numExchange;
      numBottles = numBottles - x * numExchange + x;
      ans += x;
    }
    return ans;
  }
};
