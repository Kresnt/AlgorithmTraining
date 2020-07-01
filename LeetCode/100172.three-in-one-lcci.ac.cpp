class TripleInOne {
 public:
  vector<int>stk;
  vector<int>peek_ptr;
  TripleInOne(int stackSize) {
    stk.resize(stackSize * 3);
    peek_ptr.resize(3);
    for(int i = 0; i < 3; ++i)
      peek_ptr[i] = i;
  }

  void push(int stackNum, int value) {
    if(peek_ptr[stackNum] < stk.size()) {
      stk[peek_ptr[stackNum]] = value;
      peek_ptr[stackNum] += 3;
    } else {
      /**
       * throw exception
       */
    }
  }

  int pop(int stackNum) {
    if(!isEmpty(stackNum)) {
      int ans = peek(stackNum);
      peek_ptr[stackNum] -= 3;
      return ans;
    } else {
      /**
       * throw exception
       */
      return -1;
    }
  }

  int peek(int stackNum) {
    if(!isEmpty(stackNum)) {
      return stk[peek_ptr[stackNum] - 3];
    } else {
      /**
       * throw exception
       */
      return -1;
    }
  }

  bool isEmpty(int stackNum) {
    return peek_ptr[stackNum] == stackNum;
  }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
