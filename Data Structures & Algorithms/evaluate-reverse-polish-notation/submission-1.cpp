class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i : tokens){
            if (i == "+" || i == "-" || i == "*" || i == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                switch(i[0]){
                    case '+':
                        st.push(a+b);
                        break;
                    case '-':
                        st.push(a-b);
                        break;
                    case '*':
                        st.push(a*b);
                        break;
                    case '/':
                        st.push(a/b);
                        break; 
                }
            }
            else st.push(stoi(i));
        }
        return st.top();
    }
};
