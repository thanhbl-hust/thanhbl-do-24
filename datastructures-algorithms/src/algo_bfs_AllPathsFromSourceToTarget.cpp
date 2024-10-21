class Solution {
public:
  int v[20];
  vector<int> cp;
  vector<vector<int>> p;
  void i(int n){
    v[0] = 1;
    cp.push_back(0);
    for(int i = 1; i < n; i++) v[i] = 0;
  }
  void dfs(int cur, vector<vector<int>> c){
    if(cur == c.size() - 1){
      p.push_back(cp);
      return;
    }
    for(int i = 0; i < c[cur].size(); i++){
      if(!v[c[cur][i]]){
        v[c[cur][i]] = 1;
        cp.push_back(c[cur][i]);
        dfs(c[cur][i], c);
        cp.pop_back();
        v[c[cur][i]] = 0;
      }
    }
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& c) {
    i(c.size());
    dfs(0, c);
    return p;
  }
};