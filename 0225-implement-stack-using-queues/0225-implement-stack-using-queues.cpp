class MyStack {
public:
stack<int>st;
    MyStack() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int s=st.top();
        st.pop();
        return s;
    }
    
    int top() {
       return st.top();
    }
    
    bool empty() {
        if(st.empty())return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */