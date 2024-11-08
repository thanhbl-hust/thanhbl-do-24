class Solution {
public:
  vector<vector<int>> res;
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  vector<int> pp;
  int st = -1;
  int en = -1;
  int q[10001][2];
  int N, M, rx, ry;
  int mp[100][100];
  void reset_map(){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++) mp[i][j] = 0;
    }
    mp[rx][ry] = 1;
  }
  void enQueue(int r, int c){
    en += 1;
    q[en][0] = r;
    q[en][1] = c;
  }
  void deQueue(){
    st += 1;
  }
  bool isEmpty(){
    return st == en;
  }
  void init(){
    st = en = -1;
  }
  void bfs(int r, int c){
    init();
    enQueue(r, c);
    while(!isEmpty()){
      int curr_x = q[st + 1][0], curr_y = q[st + 1][1];
      for(int i = 0; i < 4; i++){
        int newR = curr_x + dr[i];
        int newC = curr_y + dc[i];
        if(newR >= 0 && newC >= 0 && newR < N && newC < M){
          if(!mp[newR][newC]){
            enQueue(newR, newC);
            mp[newR][newC] = 1;
            pp.clear();
            pp.push_back(newR);
            pp.push_back(newC);
            res.push_back(pp);
          }
        }
      }
      deQueue();
    }
  }
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    N = rows, M = cols, rx = rCenter, ry = cCenter;
    reset_map();
    res.clear();
    pp.clear();
    pp.push_back(rCenter);
    pp.push_back(cCenter);
    res.push_back(pp);
    bfs(rx, ry);
    return res;
  }
};