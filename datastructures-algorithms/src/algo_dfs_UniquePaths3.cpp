class Solution {
public:
  int w = 0;
  int dr[4] = {0, 0, 1, -1};
  int dc[4] = {1, -1, 0, 0};
  void dfs(int r, int c, vector<vector<int>> mp){
    if(mp[r][c] == 2){
      bool satisfi = true;
      for(int i = 0; i < mp.size(); i++){
        for(int j = 0; j < mp[i].size(); j++){
          if(mp[i][j] == 0) satisfi = false;
        }
      }
      if(satisfi) w += 1;
      return;
    }
    for(int i = 0; i < 4; i++){
      int newR = r + dr[i];
      int newC = c + dc[i];
      if(newR >= 0 && newC >= 0 && newR < mp.size() && newC < mp[0].size()){
        if(mp[newR][newC] == 0 || mp[newR][newC] == 2){
          if(mp[newR][newC] == 0) mp[newR][newC] = 3;
          dfs(newR, newC, mp);
          if(mp[newR][newC] == 3) mp[newR][newC] = 0;
        }
      }
    }
  }
  int uniquePathsIII(vector<vector<int>>& grid) {
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[0].size(); j++){
        if(grid[i][j] == 1) dfs(i, j, grid);
      }
    }
    int res = w;
    return res;
  }
};