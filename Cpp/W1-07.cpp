class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0);
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            int x = s[i] - 'a';
            a[x]++;
        }

        n = t.size();
        for(int i = 0; i < n;i++){
            int x = t[i] - 'a';
            a[x]--;
        }
        for(int i = 0; i < 26;i++){
            if(a[i]){
                return false;
            }
        }
        return true;

    }
};
