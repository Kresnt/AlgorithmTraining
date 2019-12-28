class Solution {
 public:
  int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int s = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();
    if(s <= target)
      return arr[n - 1];

    int first = 0, middle;
    int half, len = arr[n - 1];
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      if(chk(middle, arr) < target) {
        first = middle + 1;
        len = len - half - 1;
      } else
        len = half;
    }
    return abs(chk(first, arr) - target) < abs(chk(first - 1, arr) - target) ? first : first - 1;
  }

  int chk(int x, vector<int>&arr) {
    int s = 0;
    for(int i = 0, n = arr.size(); i < n; ++i)
      s += min(arr[i], x);
    return s;
  }
};
