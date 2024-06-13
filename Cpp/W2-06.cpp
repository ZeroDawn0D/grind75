// O(nlgn)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[nums.size()/2];
        return ans;
    }
};


// O(n) best case

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(int i = 0; i<nums.size();i++){
            counter[nums[i]]++;
        }
        int max = -1;
        int maxi = -1;
        for(auto iter = counter.begin(); iter != counter.end(); iter++){
            if(iter->second > max){
                max = iter->second;
                maxi = iter->first;
            }
        }
        return maxi;
    }
};

// O(n) worst case and O(1) space

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candi = nums[0];
        int f = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]==candi){
                f++;
            }else{
                f--;
            }
            if(f==0){
                candi = nums[i];
                f = 1;
            }
        }
        return candi;
    }
};
