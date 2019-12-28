class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int v = -1;
    for(int n = arr.size(), i = n - 1, t; i >= 0; --i) {
      t = arr[i];
      arr[i] = v;
      v = max(v, t);
    }
    return arr;
  }
};
