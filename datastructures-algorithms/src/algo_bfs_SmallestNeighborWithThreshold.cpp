class Solution {
public:
  int st = -1;
  int en = -1;
  int q[200005][2];
  int w[101][101];
  int visit[101];
  vector<vector<int>> v;
  void init_w(int n){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        w[i][j] = 1e9;
      }
    }
  }
  void init(){
    st = en = -1;
  }
  void deQueue(){
    st += 1;
  }
  void enQueue(int v, int l){
    en += 1;
    q[en][0] = v;
    q[en][1] = l;
  }
  bool isEmpty(){
    return st == en;
  }
  void reset(int n){
    for(int i = 0; i < n; i++) visit[i] = -1;
  }
  void bfs(int vertex, int n, int mx){
    init();
    reset(n);
    enQueue(vertex, mx);
    visit[vertex] = 0;
    while(!isEmpty()){
      int currV = q[st + 1][0];
      int dis = q[st + 1][1];
      for(int i = 0; i < n; i++){
        if(w[currV][i] <= dis && dis - w[currV][i] > visit[i]){
          enQueue(i, dis - w[currV][i]);
          visit[i] = dis - w[currV][i];
        }
      }
      deQueue();
    }
    vector<int> reach;
    for(int i = 0; i < n; i++){
      if(visit[i] != -1) reach.push_back(i);
    }
    v.push_back(reach);     
  }
  int findTheCity(int n, vector<vector<int>>& e, int mx) {
    init_w(n);
    for(int i = 0; i < e.size(); i++) w[e[i][0]][e[i][1]] = w[e[i][1]][e[i][0]] = e[i][2];
    for(int i = 0; i < n; i++) bfs(i, n, mx);
    int minv = v[0].size();
    int ans = 0;
    for(int i = 1; i < v.size(); i++){
      if(v[i].size() <= minv){
        minv = v[i].size();
        ans = i;
      }
    }
    return ans;
  }
};