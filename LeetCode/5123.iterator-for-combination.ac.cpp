class CombinationIterator {
 public:
  string characters;
  string cur;
  int combinationLength;
  bool first;
  CombinationIterator(string characters, int combinationLength) {
    this->characters = characters;
    this->combinationLength = combinationLength;
    this->cur = characters.substr(0, combinationLength);
    this->first = true;
  }

  string next() {
    if(first) {
      first = false;
      return cur;
    }
    vector<int>pos;
    for(int i = 0; i < combinationLength; i++) {
      pos.push_back(characters.find_first_of(cur[i]));
    }
    for(int i = pos.size() - 1; i >= 0; --i) {
      if((i == pos.size() - 1 && pos[i] < characters.length() - 1)
          || (i < pos.size() - 1 && pos[i] + 1 != pos[i + 1])) {
        shiftPos(pos, i);
        break;
      }
    }
    cur = "";
    for(int i = 0, sz = pos.size(); i < sz; ++i)
      cur += characters[pos[i]];
    return cur;
  }

  void shiftPos(vector<int>&pos, int i) {
    pos[i]++;
    for(int j = i + 1; j < combinationLength; ++j)
      pos[j] = pos[j - 1] + 1;
  }

  bool hasNext() {
    vector<int>pos;
    for(int i = 0; i < combinationLength; i++) {
      pos.push_back(characters.find_first_of(cur[i]));
    }
    //for(auto i : pos) cout << i << " "; cout << endl;
    if(pos[0] == characters.length() - combinationLength)
      return false;
    return true;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
