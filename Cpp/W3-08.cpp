class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it = tokens.begin(); it != tokens.end();it++){
            string s = (*it);
            if(s=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b+a;
                st.push(c);
            }else if(s=="-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b-a;
                st.push(c);
            }else if(s=="*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b*a;
                st.push(c);
            }else if(s=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b/a;
                st.push(c);
            }else{
                int c = stoi(s);
                st.push(c);
            }

        }
        return st.top();
    }

};
