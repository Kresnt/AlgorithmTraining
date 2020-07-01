class LRUCache {
 private:
  struct Node {
    struct Node*prev, *next;
    int key, val;
    Node(): prev(nullptr), next(nullptr), key(0), val(0) {};
    Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {};
  };

  unordered_map<int, Node*>cache;
  Node *head, *tail;
  int size, capacity;

  inline void move_to_head(Node *targ) {
    remove_node(targ);
    insert_to_head(targ);
  }

  inline void insert_to_head(Node *targ) {
    targ->next = head->next;
    targ->prev = head;
    head->next->prev = targ;
    head->next = targ;
  }

  inline Node* remove_node(Node*targ) {
    if(targ == head || targ == tail)
      return nullptr;
    targ->prev->next = targ->next;
    targ->next->prev = targ->prev;
    targ->prev = targ->next = nullptr;
    return targ;
  }

  inline Node*remove_the_tail() {
    Node *targ = tail->prev;
    if(targ == head)
      return nullptr;
    remove_node(targ);
    return targ;
  }

 public:

  LRUCache(int _capacity) {
    head = new Node();
    tail = new Node();
    head->next = tail, tail->prev = head;
    size = 0;
    capacity = _capacity;
  }

  int get(int key) {
    if(cache.count(key) == 0)
      return -1;
    Node *tar = cache[key];
    move_to_head(tar);
    return tar->val;
  }

  void put(int key, int value) {
    Node *targ;
    if(cache.count(key) == 0) {
      targ = new Node(key, value);
      cache[key] = targ;
      insert_to_head(targ);
      size++;
      if(size > capacity) {
        Node *removed_elem = remove_the_tail();
        cache.erase(removed_elem->key);
        size--;
      }
    } else {
      targ = cache[key];
      targ->val = value;
      move_to_head(targ);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
