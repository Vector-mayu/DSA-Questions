class MedianFinder {
public:
    priority_queue<int>Left_Max_Heap; // max heap
    priority_queue<int, vector<int>, greater<int>>Right_Min_Heap; // min Heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(Left_Max_Heap.empty() || num < Left_Max_Heap.top())
        {
            Left_Max_Heap.push(num);
        }
        else
        {
            Right_Min_Heap.push(num);
        }

        // Check for Balancing of Both Heaps
        // Case 1 : diff btn both heap is greater than 1
        if((int)Left_Max_Heap.size() - (int)Right_Min_Heap.size() > 1)
        {
            Right_Min_Heap.push(Left_Max_Heap.top());
            Left_Max_Heap.pop();
        }
        // Case 2 : left max heap is lesser than right max heap
        else if(Left_Max_Heap.size() < Right_Min_Heap.size())
        {
            Left_Max_Heap.push(Right_Min_Heap.top());
            Right_Min_Heap.pop();
        }
    }
    
    double findMedian() {
        // Case 1 : Even 
        if(Left_Max_Heap.size() == Right_Min_Heap.size())
        {
            return (double)(Left_Max_Heap.top() + Right_Min_Heap.top())/2;
        }
        // Case 2 : Odd 
        return Left_Max_Heap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */ 