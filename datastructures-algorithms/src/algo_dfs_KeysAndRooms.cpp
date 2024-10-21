class Solution {
public:
  int s = -1;
  int e = -1;
  int vs[1005];
  int q[1005];
  void i(int n){
    vs[0] = 1;
    for(int i = 1; i < n; i++) vs[i] = 0;
  }
  void dq(){
    s += 1;
  }
  void eq(int r){
    e += 1;
    q[e] = r;
  }
  bool isEmpty(){
    return s == e;
  }
  void bfs(int r, vector<vector<int>> vec){
    s = e = -1;
    eq(r);
    while(!isEmpty()){
      int curr = q[s + 1];
      for(int i = 0; i < vec[curr].size(); i++){
        if(!vs[vec[curr][i]]){
          eq(vec[curr][i]);
          vs[vec[curr][i]] = 1;
        }
      }
      dq();
    }
  }
  bool canVisitAllRooms(vector<vector<int>>& v) {
    i(v.size());
    bfs(0, v);
    for(int i = 0; i < v.size(); i++){
      if(vs[i] == 0) return false;
    }
    return true;
  }
};