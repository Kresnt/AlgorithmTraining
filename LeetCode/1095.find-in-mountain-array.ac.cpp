/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
 public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    const int n = mountainArr.length();
    int l = 0, r = n - 1;
    int m, rm;
    while(l + 1 < r) {
      m = (l + r) / 2;
      rm = (m + r) / 2;
      if(mountainArr.get(m) > mountainArr.get(rm))
        r = rm;
      else
        l = m;
    }

    int mountainTopIndex = l;
    cout << mountainTopIndex  << "\n";

    int first, middle;
    int half, len;

    first = 0;
    len = mountainTopIndex + 1;
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      cout << len << " " << middle << endl;
      if(mountainArr.get(middle) < target)
        first = middle + 1, len = len - half - 1;
      else
        len = half;
    }
    cout << mountainArr.get(first) << endl;
    if(first <= mountainTopIndex && mountainArr.get(first) == target)
      return first;

    first = mountainTopIndex;
    len = n - mountainTopIndex;
    while(len > 0) {
      half = len >> 1;
      middle = first + half;
      if(mountainArr.get(middle) > target)
        first = middle + 1, len = len - half - 1;
      else
        len = half;
    }
    if(first < n && mountainArr.get(first) == target)
      return first;
    return -1;
  }
};
