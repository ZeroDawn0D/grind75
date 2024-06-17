class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        //set<vector<int>> unique;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int j = i+1;
            int k = nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    j++;
                    k--;
                }
                else if(sum>0 ){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
            }
        }
        //for(auto it = unique.begin(); it != unique.end();it++){
          //  ans.push_back(*it);
        //}
        return ans;
    }
};
