class Solution {
public:
  int cnt[2505];
  int st = -1;
  int en = -1;
  int q[2505][2];
  int v[55][55];
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  void deQueue(){
    st += 1;
  }
  void enQueue(int r, int c){
    en += 1;
    q[en][0] = r;
    q[en][1] = c;
  }
  void init(){
    st = en = -1;
  }
  bool isEmpty(){
    return st == en;
  }
  void bfs(int r, int c, int index, int N, int M, vector<vector<int>> grid){
    init();
    enQueue(r, c);
    while(!isEmpty()){
      int rr = q[st + 1][0];
      int cc = q[st + 1][1];
      for(int i = 0; i < 4; i++){
        int newR = rr + dr[i];
        int newC = cc + dc[i];
        if(newR >= 0 && newC >= 0 && newR < N && newC < M){
          if(grid[newR][newC] == 1 && v[newR][newC] == 0){
            enQueue(newR, newC);
            v[newR][newC] = 1;
            cnt[index] += 1;
          }
        }
      }
      deQueue();
    }
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0, N = grid.size(), M = grid[0].size();
    for(int i = 0; i < N * M + 1; i++) cnt[i] = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        v[i][j] = 0;
      }
    }
    int aura = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(grid[i][j] == 1 && v[i][j] == 0){
          v[i][j] = 1;
          cnt[aura] += 1;
          bfs(i, j, aura, N, M, grid);
          aura += 1;
        }
      }
    }
    for(int i = 0; i < aura + 1; i++) ans = max(ans, cnt[i]);
    return ans;
  }
};