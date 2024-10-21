class Solution {
public:
  int st = -1;
  int en = -1;
  int q[250005][2];
  int v[505][505];
  int dr[4] = {0, 0, 1, -1};
  int dc[4] = {1, -1, 0, 0};
  void init(){
    st = en = -1;
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
  bool isSize(int r, int c, int N, int M){
    if(r == 0) return true;
    if(c == 0) return true;
    if(r == N - 1) return true;
    if(c == M - 1) return true;
    return false;
  }
  void bfs(int r, int c, vector<vector<int>> grid){
    enQueue(r, c);
    v[r][c] = 1;
    while(!isEmpty()){
      int rr = q[st + 1][0];
      int cc = q[st + 1][1];
      for(int i = 0; i < 4; i++){
        int newR = rr + dr[i];
        int newC = cc + dc[i];
        if(newR >= 0 && newC >= 0 && newR < grid.size() && newC < grid[0].size()){
          if(v[newR][newC] == 0 && grid[newR][newC] == 1){
            enQueue(newR, newC);
            v[newR][newC] = 1;
          }
        }
      }
      deQueue();
    }
  }
  int numEnclaves(vector<vector<int>>& grid) {
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        v[i][j] = 0;
      }
    }
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[0].size(); j++){
        if(isSize(i, j, grid.size(), grid[0].size()) && grid[i][j] == 1 && v[i][j] == 0){
          bfs(i, j, grid);
        }
      }
    }
    int res = 0;
    for(int i = 1; i < grid.size() - 1; i++){
      for(int j = 1; j < grid[0].size() - 1; j++){
        if(grid[i][j] == 1 && v[i][j] == 0) res += 1;
      }
    }
    return res;
  }
};