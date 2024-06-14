// O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxa = nums[0];
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        for(int i = 1; i < n ;i++){
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            maxa = max(maxa,dp[i]);

        }
        return maxa;

    }
};
