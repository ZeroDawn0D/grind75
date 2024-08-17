// solution 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool present_in_substring[256];
        memset(present_in_substring,false,sizeof(present_in_substring));
        int lptr = 0, rptr = 0;
        int l = s[lptr];
        int r = s[rptr];
        int len = 0;
        int ans = 0;
        while(rptr<s.size()){
            if(present_in_substring[r]){
                present_in_substring[l] = false;
                lptr++;
                len--;
                l=s[lptr];
            }else{
                present_in_substring[r] = true;
                len++;
                if(len>ans) ans=len;
                rptr++;
                r=s[rptr];
            }
        }
        return ans;
    }
};
