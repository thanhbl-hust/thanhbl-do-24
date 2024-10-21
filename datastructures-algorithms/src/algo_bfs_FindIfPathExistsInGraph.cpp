class Solution {
public:
  int st = -1;
  int en = -1;
  int q[200005];
  int visit[200005];
  void deQueue(){
    st += 1;
  }
  void enQueue(int v){
    en += 1;
    q[en] = v;
  }
  bool isEmpty(){
    return st == en;
  }
  void made(int n){
    for(int i = 0; i < n; i++) visit[i] = 0;
  }
  void bfs(int src, int des, vector<vector<int>> v){
    enQueue(src);
    while(!isEmpty()){
      int ver = q[st + 1];
      for(int i = 0; i < v[ver].size(); i++){
        if(!visit[v[ver][i]]){
          visit[v[ver][i]] = 1;
          enQueue(v[ver][i]);
          if(v[ver][i] == des) return;
        }
      }
      deQueue();
    }
  }
  bool validPath(int n, vector<vector<int>>& edges, int src, int des){
    made(n);
    vector<vector<int>> v(n);
    for(int i = 0; i < edges.size(); i++){
      v[edges[i][0]].push_back(edges[i][1]);
      v[edges[i][1]].push_back(edges[i][0]);
    }
    visit[src] = 1;
    bfs(src, des, v);
    return visit[des];
  }
};