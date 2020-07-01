#include <bits/stdc++.h>

using namespace std;

#pragma G++ optimize("O2")

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // ö�� a
    for (int first = 0, third, second; first < n-1; ++first) {
      // ��Ҫ����һ��ö�ٵ�������ͬ
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      // c ��Ӧ��ָ���ʼָ����������Ҷ�
      third = upper_bound(nums.begin() + first, nums.end(), -nums[first] - nums[first + 1]) - nums.begin();
      third = min(n - 1, third);
      // ö�� b
      for (second = first + 1; second < n; ++second) {
        // ��Ҫ����һ��ö�ٵ�������ͬ
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }
        // ��Ҫ��֤ b ��ָ���� c ��ָ������
        int target = -nums[first] - nums[second];
        while (second < third &&  nums[third] > target) {
          --third;
        }
        // ���ָ���غϣ����� b ����������
        // �Ͳ��������� a+b+c=0 ���� b<c �� c �ˣ������˳�ѭ��
        if (second == third) {
          break;
        }
        if (-target + nums[third] == 0) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};
