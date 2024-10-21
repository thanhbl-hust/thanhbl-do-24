class Solution {
public:
  vector<int> c;
  int ret = 0;
  int s = -1;
  int e = -1;
  int m[51][51];
  int v[51];
  int q[2501];
  void i(int n){
    for(int i = 0; i < n; i++){
      v[i] = -1;
      for(int j = 0; j < n; j++){
        m[i][j] = -1;
      }
    }
  }
  void init(){
    s = e = -1;
  }
  void eq(int ver){
    e += 1;
    q[e] = ver;
  }
  void dq(){
    s += 1;
  }
  bool isempty(){
    return s == e;
  }
  void bfs(int vertex, int n){
    init();
    v[vertex] = 1;
    eq(vertex);
    while(!isempty()){
      int cur = q[s + 1];
      for(int i = 0; i < n; i++){
        if(m[cur][i] == 1 && v[i] == -1){
          v[i] = 1;
          c.push_back(i);
          eq(i);
        }
      }
      dq();
    }
  }
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    i(n);
    for(auto e : edges) m[e[0]][e[1]] = m[e[1]][e[0]] = 1;
    for(int i = 0; i < n; i++){
      if(v[i] == -1){
        c.clear();
        c.push_back(i);
        bfs(i, n);
        bool ok = true;
        for(int ii = 0; ii < c.size() - 1; ii++){
          for(int jj = ii + 1; jj < c.size(); jj++){
            if(m[c[ii]][c[jj]] != 1){
              ok = false;
              break;
            }
          }
          if(!ok) break;
        }
        if(ok) ret++;
      }
    }
    return ret;
  }
};