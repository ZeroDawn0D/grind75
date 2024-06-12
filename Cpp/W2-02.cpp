class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int mc[26] = {0};
        bool ans = true;
        for(int i = 0; i < magazine.length(); i++){
            char x = magazine[i] - 'a';
            mc[x]++;
        }
        for(int i = 0; i < ransomNote.length();i++){
            char x = ransomNote[i] - 'a';
            mc[x]--;
        }
        
        
        for(int i = 0; i < 26; i++){
            if(0 > mc[i]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};
