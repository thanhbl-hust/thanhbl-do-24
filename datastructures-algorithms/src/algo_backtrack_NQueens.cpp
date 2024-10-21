class Solution {
public:
  vector<vector<string>> root;
  int v[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  bool canPut(int index, int k){
    for(int i = 0; i < k; i++){
      if(v[i] == index) return false;
      if(abs(i - k) == abs(v[i] - index)) return false;
    }
    return true;
  }
  void backtrack(int k, int n){
    if(k == n){
      string ss = "";
      for(int i = 0; i < n; i++) ss += '.';
      vector<string> r(n, ss);
      for(int i = 0; i < n; i++){
        r[i][v[i]] = 'Q';
      }
      root.push_back(r);
      return;
    }
    for(int i = 0; i < n; i++){
      if(canPut(i, k)){
        v[k] = i;
        backtrack(k + 1, n);
        v[k] = -1;
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    backtrack(0, n);
    vector<vector<string>> ans = root;
    return ans; 
  }
};