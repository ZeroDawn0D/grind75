// O(nlgn)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int m = points[0].size();
        vector<pair<float,int>> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = {points[i][0]*points[i][0] + points[i][1]*points[i][1],i} ;

        }
        sort(ans.begin(), ans.end());
        vector<vector<int>> real_ans;
        for(auto it = ans.begin(); it != ans.begin()+k; it++){
            real_ans.push_back(points[it->second]);
        }
        return real_ans;
    }
};
