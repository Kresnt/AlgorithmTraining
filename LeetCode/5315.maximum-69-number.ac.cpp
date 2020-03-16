class Solution {
 public:
  int maximum69Number (int num) {
    char s[10];
    sprintf(s, "%d", num);
    for(int i = 0, len = strlen(s); i < len; ++i) {
      if(s[i] == '6') {
        s[i] = '9';
        break;
      }
    }
    sscanf(s, "%d", &num);
    return num;
  }
};
