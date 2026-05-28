class Solution {
  public:
  
    int findLength(Node *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
  
    int findBiggerLL(Node *head1, Node *head2){
        int len1 = findLength(head1);
        int len2 = findLength(head2);
        
        // Case1 len1 is greater
        if(len1 > len2){
            return 1;
        }
        // Case2 len2 is greater
        else if(len1 < len2){
            return 0;
        }
        // case3 both are equal
        else{
            // case 1 : if data of head 1 is greater at any node
            while(head1){
                // case 1 : if data of head 1 is greater at any node compared to head 2
                if(head1->data > head2->data){
                    return 1;
                }
                // case 2 : if data of head 2 is greater at any node compared to head 1
                else if(head1->data < head2->data){
                    return 0;
                }
                
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        // both are equal means length + values both are same, we get 0 as substraction
        return 2; // sub 0 conditon
    }
    
    Node *reverse(Node *head){
        Node *curr = head, *prev = NULL, *fut;
        
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        
        return prev;
    }
    
    Node *removeStartingZero(Node *head){
        while(head && head->data == 0){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        
        return head;
    }
  
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        if(!head1)
        return head2;
        
        if(!head2)
        return head1;
        
        Node *l1 = head1, *l2 = head2;
        int ans = findBiggerLL(l1, l2);
        
        // case1 : if len12 is greater
        if(ans == 0){
            swap(l1, l2);
        }
        else if(ans == 2){
           return new Node(0); 
        }
        
        // now reverse becuase we do subtractin with reverse
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        Node *result = NULL;
        int borrow = 0;
        
        while(l1){
            int val1 = l1->data;
            int val2 = l2 ? l2->data : 0;
            
            int diff = val1 - val2 - borrow;
            
            // if we get value in -ve -> just add +10
            if(diff < 0){
                diff += 10;
                borrow = 1;
            }
            else{
                borrow = 0;
            }
            
            // create the final node 
            Node *temp = new Node(diff);
            temp->next = result;
            result = temp;
            
            l1 = l1->next;
            // if l2 dosent exit ? just add a if statement
            if(l2){
                l2 = l2->next;
            }
        }
    
        return removeStartingZero(result);
    }
};