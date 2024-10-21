class Solution {
public:
  int s = -1;
  int e = -1;
  int q[10005];
  void init(){
    s = e = -1;
  }
  void eQ(int vv){
    e += 1;
    q[e] = vv;
  }
  void dQ(){
    s += 1;
  }
  bool isEmpty(){
    return s == e;
  }
  int r = 0;
  int v[10005];
  void i(int n){
    for(int i = 0; i < n; i++) v[i] = 0;
  }
  void bfs(int cur, vector<vector<int>> c){
    init();
    eQ(cur);
    v[cur] = 1;
    while(!isEmpty()){
      int curr = q[s + 1];
      for(int i = 0; i < c.size(); i++){
        if(!v[i] && c[curr][i]){
          eQ(i);
          v[i] = 1;
        }
      }
      dQ();
    }
  }
  int findCircleNum(vector<vector<int>>& c) {
    i(c.size());
    for(int i = 0; i < c.size(); i++){
      if(!v[i]){
        bfs(i, c);
        r += 1;
      }
    }
    return r;
  }
};