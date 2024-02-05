class MinStack {
    stack<int> mainstack;
    stack<int> minstack;

public:
    MinStack() {
    }
    
    void push(int val) {
        mainstack.push(val);
        if(minstack.empty() || val<=minstack.top()){
            minstack.push(val);
        }
    }
    
    void pop() {
        if(!mainstack.empty()){
            if(mainstack.top()==minstack.top()){
                minstack.pop();
            }
            mainstack.pop();

        }
    }
    
    int top() {
       if(!mainstack.empty()){
           return mainstack.top();
       }
       return -1;
    }
    
    int getMin() {
        if(!minstack.empty()){
            return minstack.top();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */