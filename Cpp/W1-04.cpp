class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_before_pos[n];
        min_before_pos[0] = 100000;
        if(n>1) min_before_pos[1] = prices[0];

        for(int i = 2; i < n; i++){
            if(prices[i-1] < min_before_pos[i-1]){
                min_before_pos[i] = prices[i-1];
            }else{
                min_before_pos[i] = min_before_pos[i-1];
            }
        }
        int profit = 0;
        for(int i = 0; i < n; i++){
            int diff = prices[i] - min_before_pos[i];
            if(profit < diff){
                profit = diff;
            }
        }
        return profit;
    }
};
