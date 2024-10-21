class Solution {
public: 
  bool ss = false;
  int root;
  int dr[4] = {0, 0, 1, -1};
  int dc[4] = {1, -1, 0, 0};
  int res = 0, n, m;
  int island = 1;
  int q[250001][2];
  int st = -1;
  int en = -1;
  void initq(){
    st = en = -1;
  }
  void deQueue(){
    st += 1;
  }
  void enQueue(int r, int c){
    en += 1;
    q[en][0] = r, q[en][1] = c;
  }
  bool isEmpty(){
    return st == en;
  }
  void bfss(vector<vector<int>>& mp1, vector<vector<int>> &mp2, int r, int c){
    initq();
    mp2[r][c] = 2;
    enQueue(r, c);
    while(!isEmpty()){
      int rr = q[st + 1][0];
      int cc = q[st + 1][1];
      for(int i = 0; i < 4; i++){
        int nR = rr + dr[i], nC = cc + dc[i];
        if(nR >= 0 && nC >= 0 && nR < n && nC < m){
          if(mp2[nR][nC] == 1){
            enQueue(nR, nC);
            mp2[nR][nC] = 2;
            if(mp1[nR][nC] == 0) ss = false;
          }
        }
      }
      deQueue();
    }
  }
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    n = grid1.size(), m = grid1[0].size();
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid2[i][j] == 1){
          ss = true;
          if(!grid1[i][j]) ss = false;
          bfss(grid1, grid2, i, j);
          if(ss) res += 1;
        }
      }
    }
    return res;
  }
};