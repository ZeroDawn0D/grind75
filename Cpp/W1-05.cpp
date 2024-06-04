class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> s2;
        for(int i = 0;i<s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                s2.push_back(toupper(s[i]));
            }
        }
        int n = s2.size();
        for(int i = 0; i <n/2;i++){
            if(s2[i] !=s2[n-i-1]){
                return false;
            }
        }
        return true;
    }
};
