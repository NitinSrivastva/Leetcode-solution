class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       //base case
       if(head == NULL || head->next == NULL) return head; 
       ListNode* a = head;
       ListNode* b = head->next;
       while(b!=NULL){
        while(b!=NULL && b->val == a->val){
            b = b->next;
        }
        a->next = b;
        //for next round 
       a = b;
       if(b != NULL) b = b->next;
       }
       return head;
    }
};
