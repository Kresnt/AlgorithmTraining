/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
 public:
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    int ans(0);
    if(topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]) {
      return sea.hasShips(topRight, bottomLeft) ? 1 : 0;
    } else if(!sea.hasShips(topRight, bottomLeft)) {
      return 0;
    }
    if(bottomLeft[0] < topRight[0] && bottomLeft[1] < topRight[1]) {
      int mx = (topRight[0] + bottomLeft[0]) / 2, my = (topRight[1] + bottomLeft[1]) / 2;
      ans = countShips(sea, vector<int> {mx, my}, bottomLeft)
            + countShips(sea, vector<int> {mx, topRight[1]}, vector<int> {bottomLeft[0], my + 1})
            + countShips(sea, topRight, vector<int> {mx + 1, my + 1})
            + countShips(sea, vector<int> {topRight[0], my}, vector<int> {mx + 1, bottomLeft[1]});

    } else if(bottomLeft[0] == topRight[0]) {
      int my = (topRight[1] + bottomLeft[1]) / 2;
      ans += countShips(sea, vector<int> {bottomLeft[0], my}, bottomLeft)
      + countShips(sea, topRight, vector<int> {bottomLeft[0], my + 1});
    } else if(bottomLeft[1] == topRight[1]) {
      int mx = (topRight[0] + bottomLeft[0]) / 2;
      ans = countShips(sea, vector<int> {mx, bottomLeft[1]}, bottomLeft)
      + countShips(sea, topRight, vector<int> {mx + 1, bottomLeft[1]});
    }
    return ans;
  }
};
