class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* a = head;
        ListNode* b = head;
        ListNode* mark = head;
        for(int i=1;i<k;i++){
            a = a->next;
        }
        mark = a; //mark the kth node
        //Move first to the end while advancing second to the end 
        while(a->next != NULL){
            a = a->next;
            b = b->next;
        }

        // swap values of the two nodes
        swap(mark->val , b->val);
        return head;
    }
};
