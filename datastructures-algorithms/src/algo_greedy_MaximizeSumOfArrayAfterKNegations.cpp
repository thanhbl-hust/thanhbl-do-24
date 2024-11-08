class Solution {
public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    int res = 0, c = 0, min_pos = 1e9;
    for(auto num : nums){
      res += num;
      if(num == 0) c += 1;
      if(num > 0) min_pos = min(min_pos, num);
    }
    sort(nums.begin(), nums.end());
    if(nums[0] >= 0){
      if(k % 2 == 1 && c == 0) return res - 2 * nums[0];
      return res;
    }
    int cnt = 0;
    while(cnt < nums.size()){
      if(nums[cnt] >= 0) break;
      cnt += 1;
    }
    int max_neg = nums[cnt - 1];
    cout << max_neg << endl;
    if(k <= cnt){
      for(int i = 0; i < k; i++) res += -2 * nums[i];
      return res;
    }else{
      for(int i = 0; i < cnt; i++) res += -2 * nums[i];
      k -= cnt;
      if(k % 2 == 1 && c == 0) return max(res + 2 * max_neg, res - 2 * min_pos);
      return res;
    }
    return -1;
  }
};