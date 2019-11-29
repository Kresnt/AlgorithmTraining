# define se second

class Solution {
 public:
  const int dx[2] = {-1, 1};
  int candy(vector<int>& ratings) {
    int n  = ratings.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
    for(int i = 0; i < n; ++i)
      que.push(make_pair(ratings[i], i));
    vector<int>candies(n);
    while(!que.empty()) {
      pair<int, int> p = que.top();
      que.pop();
      candies[p.se] = 1;
      for(int i = 0, x; i < 2; ++i) {
        x = p.se + dx[i];
        if(x >= 0 && x < n && ratings[x] < ratings[p.se])
          candies[p.se] = max(candies[p.se], candies[x] + 1);
      }
    }
    return accumulate(candies.begin(), candies.end(), 0);
  }
};
