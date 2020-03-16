class Solution {
public:
    /**
	 * Brute
	 */
	vector<int> distributeCandies(int candies, int num_people) {
      vector<int>ans(num_people);
      for(int i = 0,j=1;candies;i = (i+1)%num_people,j++)
        if(j <= candies) ans[i] += j,candies -= j;
        else ans[i]+=cnadies,candies-= candies;
      return ans;
    }
};