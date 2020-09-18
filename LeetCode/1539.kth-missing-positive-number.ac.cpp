class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    vector<bool>vis(arr.size() + k + 1);
    for(int i = 0; i < arr.size(); i++)
      if(arr[i] < vis.size())
        vis[arr[i]] = true;
    for(int i = 1, c = 0; i < vis.size(); i++) {
      if(!vis[i])
        c++;
      if(c == k)
        return i;
    }
    return vis.size();
  }
};
