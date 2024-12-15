class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> s;
    long minE;
    
    public:
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            minE = x;
        }
        else if(x>=minE) s.push(x);
        else {
            s.push((long)2*x-minE);
            minE=x;
        }
    }
    
    void pop() {
        if(s.top()<minE)
            minE= 2*minE-s.top();
        s.pop();
    }
    
    int top() {
        if(s.empty())
            return -1;
        if(s.top()<minE)
            return minE;
        return s.top();
    }
    
    int getMin() {
        if(s.empty())
            return -1;
        return minE;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */