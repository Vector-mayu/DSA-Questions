class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
        return NULL;

        if(!head->next)
        return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            break;
        }

        if(slow != fast)
        return NULL;

        if(slow == head)
        return head;

        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};