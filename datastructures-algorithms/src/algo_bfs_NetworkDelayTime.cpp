class Solution {
public:
  int ans = -1;
  int visit[101];
  int w[101][101];
  int q[100005][2];
  int st = -1;
  int en = -1;
  void init(int n){
    for(int i = 1; i < n + 1; i++){
      for(int j = 1; j < n + 1; j++){
        w[i][j] = -1;
      }
    }
  }
  void reset(int n){
    for(int i = 1; i < n + 1; i++) visit[i] = -1;
  }
  void deQueue(){
    st += 1;
  }
  void enQueue(int v, int tm){
    en += 1;
    q[en][0] = v;
    q[en][1] = tm;
  }
  bool isEmpty(){
    return st == en;
  }
  void bfs(int v, int n, int tm){
    enQueue(v, tm);
    while(!isEmpty()){
      int vv = q[st + 1][0];
      int tmm = q[st + 1][1];
      for(int i = 1; i < n + 1; i++){
        if(w[vv][i] != -1 && (tmm + w[vv][i] < visit[i] || visit[i] == -1)){
          enQueue(i, tmm + w[vv][i]);
          visit[i] = tmm + w[vv][i];
        }
      }
      deQueue();
    }
  }
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    init(n);
    reset(n);
    for(int i = 0; i < times.size(); i++){
      w[times[i][0]][times[i][1]] = times[i][2];
    }
    visit[k] = 0;
    bfs(k, n, 0);
    for(int i = 1; i < n + 1; i++){
      if(visit[i] == -1) return -1;
      ans = max(ans, visit[i]);
    }
    return ans;
  }
};