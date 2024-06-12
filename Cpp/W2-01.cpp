// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int ans = 0;
        while(left<=right){
            int m = left + (right-left)/2;
            if(!isBadVersion(m)){
                left = m+1;
            }
            else if(isBadVersion(m) && !isBadVersion(m-1)){
                return m;
            }
            else{
                right = m-1;
            }

        }
        return ans;
    }
};
