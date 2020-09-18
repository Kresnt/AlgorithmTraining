class Solution {
 public:
  int getWinner(vector<int>& arr, const int k) {
    int x = arr[0], c = 0;
    for(int i = 1; i < arr.size(); i++) {
      if(x > arr[i])
        c++;
      else
        x = arr[i], c = 1;
      if(c >= k)
        return x;
    }
    return x;
  }
};
