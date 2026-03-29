class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string accept = "([{";
        for (char c: s){
            if (accept.contains(c)) st.push(c);
            else {
                if (st.empty()) return false;
                else if (c == ')'){
                    if (st.top() == '(') st.pop();
                    else return false;
                }else if (c == ']'){
                    if (st.top() == '[') st.pop();
                    else return false;
                }else if (c == '}'){
                    if (st.top() == '{') st.pop();
                    else return false;
                }else return false;
            }
        }

        return st.empty() ? true : false;
    }
};
