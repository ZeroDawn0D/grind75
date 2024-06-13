class Solution {
public:
    string addBinary(string a, string b) {
        
        while(a.size()<b.size()){
            a = "0" + a;
        }
        while(b.size()<a.size()){
            b = "0" + b;
        }
        int sum = 0;
        int carry = 0;
        string ans = "";
        for(int i = a.size()-1; i>=0; i--){
            int ad = a[i] - '0';
            int bd = b[i] - '0';
            sum = ad ^ bd ^ carry;
            carry = (ad & bd) | (ad&carry) | (bd&carry);
            ans = (char)(sum+'0') + ans;
        }
        if(carry==1){
            ans = "1" + ans;
        }
        return ans;
    }
};
