class CustomStack {
    vector<int> st;
    int size;
    int top = -1;
public:
    CustomStack(int maxSize) {
        st = vector<int>(maxSize, -1);
        size = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top+1 < size){
            st[++top] = x;
        }
    }
    
    int pop() {
        if (top == -1) return -1; 
        return st[top--];
    }
    
    void increment(int k, int val) {
        int limit = min(k, top + 1);  
       
        for(int i=0;i<limit;i++){
            st[i]+=val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */