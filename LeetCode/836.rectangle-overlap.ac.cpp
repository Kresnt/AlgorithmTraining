class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return isOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) &&
           isOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
  }

  inline bool isOverlap(int l1, int r1, int l2, int r2) {
    return !(l1 >= r2 || l2 >= r1);
  }
};
