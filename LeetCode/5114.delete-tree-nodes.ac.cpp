#define PB push_back

typedef pair<int,int> PII;

class Solution {
public:
    static const int maxn = 1e4+7;
    vector<int> g[maxn];
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
      int root(-1);  
      for(int i = 0;i < nodes;++i){
        if(parent[i] == -1) root = i;
        else g[parent[i]].PB(i);
      }
      return DFS(value,root).second;
    }
    
  pair<int,int> DFS(vector<int>&value,int root){
    PII ans({value[root],1});//{values,size}
    for(int u:g[root]){
      PII sub = DFS(value,u);
      if(sub.first != 0) ans.first += sub.first,ans.second += sub.second;
    }
    return ans;
  }
  
};