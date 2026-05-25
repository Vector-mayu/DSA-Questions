// Time Complexity 
// TC = O(k Logk*n)
class Solution {
public:

    ListNode *mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
                tail->next = NULL;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }

        while(list1){
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
            tail->next = NULL;
        }

        while(list2){
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
            tail->next = NULL;
        }

        return head->next;
    }

    ListNode *mergeSort(vector<ListNode*>&arr, int start, int end){
        // base case
        if(start == end){
            return arr[start];
        }
        // mid calculation
        int mid = start + (end - start)/2;
        //left
        ListNode *head1 = mergeSort(arr, start, mid);
        // right
        ListNode *head2 = mergeSort(arr, mid+1, end);

        // merge two sroted linkedlist code 
        return mergeTwoLists(head1, head2);

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
        return NULL;
        return mergeSort(lists, 0, lists.size()-1);
    }
};