class Solution {
public:
  int st = -1;
  int en = -1;
  int q[2505][2];
  int v[55][55];
  int dc[4] = {0, 0, 1, -1};
  int dr[4] = {1, -1, 0, 0};
  void deQueue(){
    st += 1;
  }
  void enQueue(int r, int c){
    en += 1;
    q[en][0] = r;
    q[en][1] = c;
  }
  bool isEmpty(){
    return st == en;
  }
  void bfs(int r, int c, vector<vector<int>> m){
    enQueue(r, c);
    while(!isEmpty()){
      int rr = q[st + 1][0];
      int cc = q[st + 1][1];
      for(int i = 0; i < 4; i++){
        int newR = rr + dr[i];
        int newC = cc + dc[i];
        if(newR >= 0 && newC >= 0 && newR < m.size() && newC < m[0].size()){
          if(m[newR][newC] == m[r][c] && v[newR][newC] == 0){
            enQueue(newR, newC);
            v[newR][newC] = 1;
          }
        }
      }
      deQueue();
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>>& m, int r, int c, int color) {
    for(int i = 0; i < m.size(); i++){
      for(int j = 0; j < m[0].size(); j++){
        v[i][j] = 0;
      }
    }
    v[r][c] = 1;
    bfs(r, c, m);
    for(int i = 0; i < m.size(); i++){
      for(int j = 0; j < m[0].size(); j++){
        if(v[i][j] == 1) m[i][j] = color;
      }
    }
    return m;
  }
};