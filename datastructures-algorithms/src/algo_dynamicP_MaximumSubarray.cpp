class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp = {nums[0]};
    for(int i = 1; i < nums.size(); i++){
      dp.push_back(max(nums[i], nums[i] + dp[dp.size() - 1]));
    }
    return *max_element(dp.begin(), dp.end());
  }
};