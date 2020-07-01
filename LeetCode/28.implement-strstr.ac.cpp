#pragma G++ optimize("O2")

class Solution {
 public:
  int strStr(string haystack, string needle) {
    //cout << haystack.length()-needle.length()<<endl;
    for(int i = 0; i <= (int)haystack.length() - (int)needle.length(); i++) {
      bool flag(true);
      for(int j = 0; j < needle.size(); j++)
        if(haystack[i + j] != needle[j]) {
          flag = false;
          break;
        }
      if(flag)
        return i;
    }
    return -1;
  }
};
