class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> res;
    int dif = 1e9, index = -1;
    for(int i = 0; i < arr.size(); i++){
      if(abs(arr[i] - x) < dif){
        dif = abs(arr[i] - x);
        index = i;
      }
    }
    if(index == 0){
      for(int i = 0; i < k; i++) res.push_back(arr[i]);
      sort(res.begin(), res.end());
      return res;
    }else if(index == arr.size() - 1){
      for(int i = arr.size() - 1; i > arr.size() - 1 - k; i--) res.push_back(arr[i]);
      sort(res.begin(), res.end());
      return res;
    }
    int l, r;
    if(abs(arr[index - 1] - x) <= abs(arr[index])){
      l = index - 1;
      r = index;
    }else{
      r = index + 1;
      l = index;
    }
    while(l >= 0 and r <= arr.size() - 1 and res.size() < k){
      if(abs(arr[l] - x) <= abs(arr[r] - x)){
        res.push_back(arr[l]);
        l -= 1;
      }else{
        res.push_back(arr[r]);
        r += 1;
      }
    }
    while(l >= 0 and res.size() < k){
      res.push_back(arr[l]);
      l -= 1;
    }
    while(r < arr.size() && res.size() < k){
      res.push_back(arr[r]);
      r += 1;
    }
    sort(res.begin(), res.end());
    return res;
  }
};