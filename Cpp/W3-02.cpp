class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int INF = 100000;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> temp(n,INF);
        vector<vector<int>> ans(m,temp);
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    continue;
                }
                if(i>0){
                    ans[i][j] = min(ans[i][j],1+ans[i-1][j]);
                }
                if(j>0){
                    ans[i][j] = min(ans[i][j],1+ans[i][j-1]);
                }
            }
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j>=0; j--){
                if(i != m-1 ){
                    ans[i][j] = min(ans[i][j],1+ans[i+1][j]);
                }
                if(j!= n-1){
                    ans[i][j] = min(ans[i][j],1+ans[i][j+1]);
                }
            }
        }
        return ans;
        
    }
};
