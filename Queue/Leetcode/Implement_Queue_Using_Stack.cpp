class MyQueue {
public:
    stack<int>rev;
    stack<int>nor;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(rev.empty() && nor.empty()){
            rev.push(x);
        }
        else if(!rev.empty()){
            rev.push(x);
        }
        else{
            while(!nor.empty()){
                rev.push(nor.top());
                nor.pop();
            }
            rev.push(x);
        }
    }
    
    int pop() {
        if(rev.empty() && nor.empty()){
            return -1;
        }
        else if(!rev.empty()){
            while(rev.size() > 1){
                nor.push(rev.top());
                rev.pop();
            }
            int target = rev.top();
            rev.pop();
            return target;
        }
        else{
            int target = nor.top();
            nor.pop();
            return target;
        }
    }
    
    int peek() {
        if(rev.empty() && nor.empty()){
            return -1;
        }
        else if(!rev.empty()){
            while(!rev.empty()){
                nor.push(rev.top());
                rev.pop();
            }
            return nor.top();
        }
        else{
            return nor.top();
        }
    }
    
    bool empty() {
        return rev.empty() && nor.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */