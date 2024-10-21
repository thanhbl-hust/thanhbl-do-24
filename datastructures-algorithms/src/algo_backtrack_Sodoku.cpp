class Solution {
public:
  bool ok = false;
  int row[9][10];
  int col[9][10];
  int dia[9][10];
  vector<vector<char>> cc;
  int coor(int r, int c){
    if(r < 3){
      if(c < 3) return 0;
      if(c < 6) return 1;
      return 2;
    }else if(r < 6){
      if(c < 3) return 3;
      if(c < 6) return 4;
      return 5;
    }else{
      if(c < 3) return 6;
      if(c < 6) return 7;
    }
    return 8;
  }
  void init(){
    for(int i = 0; i < 9; i++){
      for(int j = 1; j < 10; j++){
        row[i][j] = col[i][j] = dia[i][j] = 0;
      }
    }
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        if(cc[i][j] != '.'){
          row[i][(int)cc[i][j] - (int)('0')] = 1;
          col[j][(int)cc[i][j] - (int)('0')] = 1;
          dia[coor(i, j)][(int)cc[i][j] - (int)('0')] = 1;
        }
      }
    }
  }
  void backtrack(int k, vector<vector<char>>& res){
    if(ok) return;
    if(k == 81){
      for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
          res[i][j] = cc[i][j];
        }
        cout << endl;
      }
      ok = true;
      return;
    }     
    int r = k / 9, c = k % 9;
    if(cc[r][c] == '.'){
      vector<int> could;
      for(int i = 1; i < 10; i++){
        if(row[r][i] == 0 && col[c][i] == 0 && dia[coor(r, c)][i] == 0) could.push_back(i);
      }
      for(auto u : could){
        cc[r][c] = '0' + u;
        row[r][u] = 1;
        col[c][u] = 1;
        dia[coor(r, c)][u] = 1;
        backtrack(k + 1, res);
        cc[r][c] = '.';
        row[r][u] = 0;
        col[c][u] = 0;
        dia[coor(r, c)][u] = 0;
      }
    }else{
      backtrack(k + 1, res);
    }
  }
  void solveSudoku(vector<vector<char>>& board) {
    for(auto v : board) cc.push_back(v);
    init();
    backtrack(0, board);
  }
};