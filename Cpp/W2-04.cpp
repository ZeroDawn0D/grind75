class Solution {
public:
    int longestPalindrome(string s) {
        bool has_odd = false;
        int c[52] = {0};
        for(int i = 0; i < s.size(); i++){
            char x = s[i];
            if(x<='Z'){
                c[x-'A']++;
            }else{
                c[x-'a'+26]++;
            }
        }
        int sum = 0;
        for(int i = 0; i < 52; i++){
            if(c[i]%2==1){
                has_odd = true;
                sum += c[i]-1;
            }else{
                sum += c[i];
            }
        }
        if(has_odd){
            sum++;
        }
        return sum;
    }
};
