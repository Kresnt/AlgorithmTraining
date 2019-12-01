class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if(tomatoSlices > cheeseSlices * 4)
      return vector<int> {};
    vector<int> ans(2);
    ans[1] = cheeseSlices;
    tomatoSlices -= 2 * cheeseSlices;
    if(tomatoSlices < 0 || (tomatoSlices & 1))
      return vector<int> {};
    ans[1] -= tomatoSlices / 2;
    ans[0] += tomatoSlices / 2;
    tomatoSlices -= tomatoSlices - (tomatoSlices & 1);
    if(tomatoSlices != 0)
      return vector<int> {};
    return ans;
  }
};
