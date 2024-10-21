class Solution {
public:
  int ret = 0;
  int st = -1;
  int en = -1;
  int q[10005][2];
  int v[101][101];
  bool isClose = true;
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  void i(int n, int m){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        v[i][j] = 0;
      }
    }
  }
  bool isEmpty(){
    return st == en;
  }
  void eq(int r, int c){
    en += 1;
    q[en][0] = r;
    q[en][1] = c;
  }
  void dq(){
    st += 1;
  }
  void init(){
    st = en = -1;
  }
  bool isSide(int r, int c, int n, int m){
    if(r == 0 || c == 0) return true;
    if(r == n - 1 || c == m - 1) return true;
    return false;
  }
  void bfs(int r, int c, vector<vector<int>> mp){
    cout << "Running BFS at " << r << " and " << c << endl;
    isClose = true;
    init();
    eq(r, c);
    v[r][c] = 1;
    if(isSide(r, c, mp.size(), mp[0].size())) isClose = false;
    while(!isEmpty()){
      int rr = q[st + 1][0];
      int cc = q[st + 1][1];
      for(int i = 0; i < 4; i++){
        int nR = rr + dr[i];
        int nC = cc + dc[i];
        if(nR >= 0 && nC >= 0 && nR < mp.size() && nC < mp[0].size()){
          if(mp[nR][nC] == 0 && v[nR][nC] == 0){
            eq(nR, nC);
            v[nR][nC] = 1;
            if(isSide(nR, nC, mp.size(), mp[0].size())) isClose = false;
          }
        }
      }
      dq();
    }
  }
  int closedIsland(vector<vector<int>>& mp) {
    i(mp.size(), mp[0].size());
    for(int i = 0; i < mp.size(); i++){
      for(int j = 0; j < mp[i].size(); j++){
        if(mp[i][j] == 0 && !v[i][j]){
          bfs(i, j, mp);
          if(isClose) ret++;
        }
      }
    }
    return ret;
  }
};