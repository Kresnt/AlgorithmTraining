#pragma GCC optimize(2)
#pragma G++ optimize(2)

class Solution {
 public:
  enum State {
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END,
  };

  enum CharType {
    CHAR_NUMBER,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_SPACE,
    CHAR_ILLEGAL,
  };

  const vector<unordered_map<CharType, State>> transfer =
      vector<unordered_map<CharType, State>>({{
                                                  {CHAR_SPACE, STATE_INITIAL},
                                                  {CHAR_NUMBER, STATE_INTEGER},
                                                  {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                                                  {CHAR_SIGN, STATE_INT_SIGN},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_INTEGER},
                                                  {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_INTEGER},
                                                  {CHAR_EXP, STATE_EXP},
                                                  {CHAR_POINT, STATE_POINT},
                                                  {CHAR_SPACE, STATE_END},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_FRACTION},
                                                  {CHAR_EXP, STATE_EXP},
                                                  {CHAR_SPACE, STATE_END},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_FRACTION},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_FRACTION},
                                                  {CHAR_EXP, STATE_EXP},
                                                  {CHAR_SPACE, STATE_END},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_EXP_NUMBER},
                                                  {CHAR_SIGN, STATE_EXP_SIGN},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_EXP_NUMBER},
                                              },
                                              {
                                                  {CHAR_NUMBER, STATE_EXP_NUMBER},
                                                  {CHAR_SPACE, STATE_END},
                                              },
                                              {
                                                  {CHAR_SPACE, STATE_END},
                                              }});

  CharType toCharType(char ch) const {
    if (ch >= '0' && ch <= '9') {
      return CHAR_NUMBER;
    } else if (ch == 'e' || ch == 'E') {
      return CHAR_EXP;
    } else if (ch == '.') {
      return CHAR_POINT;
    } else if (ch == '+' || ch == '-') {
      return CHAR_SIGN;
    } else if (ch == ' ') {
      return CHAR_SPACE;
    } else {
      return CHAR_ILLEGAL;
    }
  }

  bool isNumber(string& s) const {
    int len = s.length();
    State st = STATE_INITIAL;

    for (int i = 0; i < len; i++) {
      CharType typ = toCharType(s[i]);
      auto it = transfer[st].find(typ);
      if (it == transfer[st].end()) {
        return false;
      } else {
        st = it->second;
      }
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER ||
           st == STATE_END;
  }
};