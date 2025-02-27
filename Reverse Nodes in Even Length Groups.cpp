class Solution {
public:
 ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
        ListNode* reverseBetween(ListNode* head, int left, int right) {
        // base case
        if(left == right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
        while(temp != NULL){
            if(n == left-1) a = temp;
            if(n == left) b = temp;
            if(n == right) c = temp;
            if(n == right+1) d = temp;
            n++;
            temp = temp->next;
        }
        // breaking the list 
        if(a != NULL) a->next = NULL;
        c->next = NULL;

        c = reverseList(b);

        //join the break list
        if(a != NULL) a->next = c;
        b->next = d;

        if(a != NULL) return head;
        return c;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while(temp!=NULL && temp->next != NULL){
            int remlen = 0;
            ListNode* t = temp->next;
            for(int i=1;i<=gap+1 && t!=NULL;i++){
                t = t->next;
                remlen++;
            }
            if(remlen<gap+1) gap = remlen - 1;
            if(gap % 2 != 0) reverseBetween(temp,2,gap+2);
            gap++;
            for(int i=1;temp!=NULL && i<=gap;i++){
                temp = temp->next;
            }
        }
        return head;
    }
};
