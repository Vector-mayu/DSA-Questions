class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        // if q1 is not empty then push in q1 
        // else push in q2
        if(q1.empty() && q2.empty()){
            q1.push(x);
        }
        else if(!q1.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        if(q1.empty() && q2.empty()){
            return -1;
        }
        else if(!q1.empty()){
            int target = q1.back();
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            return target;
        }
        else{
            int target = q2.back();
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
            return target;
        }
    }
    
    int top() {
        if(!q1.empty()){
            return q1.back();
        }
        else if(!q2.empty()){
            return q2.back();
        }
        else{
            return -1;
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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