class SpecialStack {
  public:
    stack<int> st;
    stack<int> gmin;
    
    SpecialStack(){}

    void push(int x) {
        st.push(x);

        if (gmin.empty() || x <= gmin.top()) {
            gmin.push(x);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if (st.empty()) return;

        if (st.top() == gmin.top()) {
            gmin.pop();
        }
        st.pop();
    }

    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        if (gmin.empty()) return -1;
        return gmin.top();
    }
};