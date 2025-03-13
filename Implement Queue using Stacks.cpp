class MyQueue {
public:
stack<int>st;
stack<int>gt;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty()){
            gt.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!gt.empty()){
            st.push(gt.top());
            gt.pop();
        }
    }

    int pop() {
        int ans = st.top();
        st.pop();
        return ans;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};
