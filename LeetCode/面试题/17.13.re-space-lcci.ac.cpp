class Solution {
 public:
  int respace(vector<string>& dictionary, string sentence) {
    sort(dictionary.begin(), dictionary.end());
    if(dictionary.size() == 0)
      return sentence.length();

    vector<int>ans(sentence.length() + 1, 0);
    for(int p = sentence.length() - 1; p >= 0; p--) {
      string sub = sentence.substr(p, sentence.length() - p);
      ans[p] = ans[p + 1] + 1;
      for(int i = upper_bound(dictionary.begin(), dictionary.end(), sub) - dictionary.begin() - 1; i >= 0; i--) {
        if(dictionary[i][0] < sub[0] || ans[p] == 0)
          break;
        if(sub.length() < dictionary[i].length())
          continue;
        if(strncmp(sub.c_str(), dictionary[i].c_str(), dictionary[i].length()) == 0) {
          ans[p] = min(ans[p], ans[p + dictionary[i].length()]);
        }
      }
    }
    return ans[0];
  }
};
