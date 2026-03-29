class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size(),0);
        stack<int> st;
        st.push(0);
        for (int r = 1; r < temp.size(); r++){
            
            while (!st.empty() && temp[st.top()] < temp[r]){
                res[st.top()] = r - st.top();
                st.pop();
            }
            st.push(r);
        }

        return res;
    }
};
