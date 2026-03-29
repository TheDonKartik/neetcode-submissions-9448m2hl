class MinStack {
public:
    vector<int> st;
    vector<int> mini;
    MinStack() {

    }
    
    void push(int val) {
        st.insert(st.begin(), val);
        if (mini.empty()) mini.insert(mini.begin(), val);
        // int m = mi(val,min[0]);
        else mini.insert(mini.begin(), min(val,mini[0]));
    }
    
    void pop() {
        if (st.empty()) return;
        st.erase(st.begin());
        mini.erase(mini.begin());
    }
    
    int top() {
        return st[0];
    }
    
    int getMin() {
        return mini[0];
    }
};
