// Brute Force Approach :- MinHeap 
// TC = Insertion in MinHeap = LogN , Pop operation = LogN
// Total TC = O(NlogN) // poor

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        Node *hor = root;
        Node *ver = root;
        
        while(hor){
            while(ver){
                pq.push(ver->data);
                ver = ver->bottom;
            }
            hor = hor->next;
            ver = hor;
        }
        
        Node *temp = new Node(0);
        Node *tail = temp;
        
        while(!pq.empty()){
            Node *curr = new Node(pq.top());
            pq.pop();
            tail->bottom = curr;
            tail = tail->bottom;
        }
        
        return temp->bottom;
    }
};

// # Approach 2 :- Merge Sort Approach
// TC = O(KLognN)

class Solution {
  public:
  
    Node *MergeTwoLL(Node *head1, Node *head2){
        if(!head1)
        return head2;
        
        if(!head2)
        return head1;
        
        Node *head = new Node(0);
        Node *tail = head;
        
        // merging both LL
        while(head1 && head2){
            if(head1->data <= head2->data){
                tail->bottom = head1;
                tail = tail->bottom;
                head1 = head1->bottom;
                tail->bottom = NULL;
            }
            else{
                tail->bottom = head2;
                tail = tail->bottom;
                head2 = head2->bottom;
                tail->bottom = NULL;
            }
        }
        
        while(head1){
                tail->bottom = head1;
                tail = tail->bottom;
                head1 = head1->bottom;
                tail->bottom = NULL;
            }
            
        while(head2){
            tail->bottom = head2;
            tail = tail->bottom;
            head2 = head2->bottom;
            tail->bottom = NULL;
        }
            
        return head->bottom;
    }
  
    Node *MergeSort(vector<Node*>&arr, int start, int end){
        // base case
        if(start == end)
        return arr[start];
        
        int mid = start+(end-start)/2;
        Node *head1 = MergeSort(arr, start, mid);
        Node *head2 = MergeSort(arr, mid+1, end);
        
        return MergeTwoLL(head1, head2);
        
    }
  
    Node *flatten(Node *root) {
        // code here
        vector<Node*>arr;
        Node *temp = root;
        while(temp){
            arr.push_back(temp);
            temp = temp->next;
        }
        
        return MergeSort(arr, 0, arr.size()-1);
        
    }
};