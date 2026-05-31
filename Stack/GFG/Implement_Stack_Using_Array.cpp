class myStack {
  public:
    int size;
    int index;
    int arr[1000];
    
    myStack(int n) {
        index = -1;
        size = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return index == -1;
    }

    bool isFull() {
        // check if the stack is full
        return index == size-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(!isFull()){
            index++;
            arr[index] = x;
        }
        else{
            return;
        }
        
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty())
        return;
        else{
            index--;
            return;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(!isEmpty()){
            return arr[index];
        }
        else
        return -1;
    }
};