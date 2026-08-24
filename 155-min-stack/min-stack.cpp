class MinStack {
public:
    vector<int> st;
    int mini = INT_MAX;

    MinStack() {
    }
    
    void push(int value) {
        st.push_back(value);
        mini = min(mini, value);
    }
    
    void pop() {
        st.pop_back();

        mini = INT_MAX;
        for (int x : st) {
            mini = min(mini, x);
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mini;
    }
};