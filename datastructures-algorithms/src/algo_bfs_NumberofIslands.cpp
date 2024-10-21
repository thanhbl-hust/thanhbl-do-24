class Solution {
public:
  int st = -1;
  int en = -1;
  int q[90005][2];
  int visit[301][301];
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  void init(int n, int m){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        visit[i][j] = 0;
      }
    }
  }
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
  void initial(){
    st = en = -1;
  }
  void bfs(int r, int c, vector<vector<char>> v){
    initial();
    enQueue(r, c);
    visit[r][c] = 1;
    while(!isEmpty()){
      int rr = q[st + 1][0];
      int cc = q[st + 1][1];
      for(int i = 0; i < 4; i++){
        int newR = rr + dr[i];
        int newC = cc + dc[i];
        if(newR >= 0 && newC >= 0 && newR < v.size() && newC < v[0].size()){
          if(visit[newR][newC] == 0 && v[newR][newC] == v[rr][cc]){
            cout << "Enqueue " << newR << " " << newC << endl;
            enQueue(newR, newC);
            visit[newR][newC] = 1;
          }
        }
      }
      deQueue();
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    init(grid.size(), grid[0].size());
    int res = 0;
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        if(grid[i][j] == '1' && visit[i][j] == 0){
          res += 1;
          bfs(i, j, grid);
        }
      }
    }
    return res;
  }
};