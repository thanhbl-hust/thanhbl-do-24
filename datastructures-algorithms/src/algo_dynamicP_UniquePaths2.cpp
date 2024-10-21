class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& v) {
    if(v[0][0] == 1) return 0;
    if(v.size() == 1 && v[0].size() == 1) return 1 - v[0][0];
    vector<vector<int>> c(v.size(), vector<int> (v[0].size(), 0));
    int rr = 0, cc = 1;
    while(cc < c[0].size()){
      if(v[rr][cc] == 1) break;
      c[rr][cc] = 1;
      cc++;
    }
    rr = 1;
    cc = 0;
    while(rr < c.size()){
      if(v[rr][cc] == 1) break;
      c[rr][cc] = 1;
      rr++;
    }
    for(int i = 1; i < c.size(); i++){
      for(int j = 1; j < c[i].size(); j++){
        if(v[i][j] != 1) c[i][j] = c[i - 1][j] + c[i][j - 1];
      }
    }
    return c[c.size() - 1][c[0].size() - 1];
  }
};