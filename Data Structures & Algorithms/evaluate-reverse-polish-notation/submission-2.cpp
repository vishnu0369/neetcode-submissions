class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(string &i : tokens) {
            if(i != "+" && i != "-" && i != "*" && i != "/")
                st.push(stoi(i));
            else {
                int n2 = st.top();  st.pop();
                int n1 = st.top();  st.pop();

                if(i == "+")
                    st.push(n1 + n2);
                else if(i == "-")
                    st.push(n1 - n2);
                else if(i == "*")
                    st.push(n1 * n2);
                else if(i == "/")
                    st.push(n1/n2);
            }
        }
        return st.top();
    }
};