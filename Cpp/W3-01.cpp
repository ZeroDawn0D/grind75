class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = -1;
        bool used = false;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval[1] < intervals[0][0]){
            ans.push_back(newInterval);
            start = -1;
            used = true;
        }

        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] < newInterval[0] && intervals[i][1] < newInterval[0]){
                //ans.push_back(intervals[i]);
                start = intervals[i][0];
                end = intervals[i][1];
                //continue;
            }
            else if(intervals[i][0] > newInterval[1] && intervals[i][0] > newInterval[1]){
                //ans.push_back(intervals[i]);
                start = intervals[i][0];
                end = intervals[i][1];
                //continue;
            }

            if(start!=-1 && end != -1){
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start = -1;
                end = -1;
                continue;
            }

            if(intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1]){
                start = intervals[i][0];
                used = true;
            }
            else if(i>0 && (intervals[i-1][1]<newInterval[0] && newInterval[0]<intervals[i][0])){
                start = newInterval[0];
                used = true;
            }


            if(intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1]){
                end = intervals[i][1];
                used = true;
            }
            else if((i==intervals.size()-1 && (newInterval[1] > intervals[i][1]) )){
                end = newInterval[1];
                used= true;
            }
            else if(i<intervals.size()-1 && (intervals[i][1] < newInterval[1] && newInterval[1]<intervals[i+1][0] ) ){
                end = newInterval[1];
                used = true;
            }
            
            if(start!=-1 && end != -1){
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start = -1;
                end = -1;
            }
        }

        if( intervals[intervals.size()-1][1] < newInterval[0]){
            ans.push_back(newInterval);
            used = true;
        }
        if(!used){
            for(int i = 0; i<intervals.size()-1;i++){
                if(intervals[i][1] < newInterval[0] && newInterval[1] < intervals[i+1][0]){
                    ans.insert(ans.begin()+1+i,newInterval);
                }
            }

        }

        return ans;
    }
};
