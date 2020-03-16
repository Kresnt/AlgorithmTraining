class Solution {
    public String compressString(String S) {
      if(S.length() == 0 ) return S;
      StringBuilder ans = new StringBuilder();
      char c = S.charAt(0);
      Integer cnt = 0;
      for(int i = 0,sz = S.length();i < sz;++i){
        if(c == S.charAt(i)) {
          cnt ++;
        }
        else {
          ans.append(c);
          ans.append(cnt);
          cnt=1;
          c = S.charAt(i);
        }
      }
      ans.append(c);
      ans.append(cnt);
      return ans.toString().length() >= S.length() ? S : ans.toString();
    }
}