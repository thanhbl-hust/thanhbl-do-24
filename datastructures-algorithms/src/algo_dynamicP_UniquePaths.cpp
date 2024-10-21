class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> c(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++) c[i][0] = 1;
    for(int i = 0; i < n; i++) c[0][i] = 1;
    for(int i = 1; i < m; i++){
      for(int j = 1; j < n; j++){
        c[i][j] = c[i - 1][j] + c[i][j - 1];
      }
    }
    return c[m - 1][n - 1];
  }
};