class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [&](auto a, auto b) { return a[1] > b[1]; });
    int ans(0);
    for (int i = 0; i < boxTypes.size(); i++) {
      int x = min(boxTypes[i][0], truckSize);
      ans += boxTypes[i][1] * x;
      truckSize -= x;
    }
    return ans;
  }
};