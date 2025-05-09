class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        //Method 1 using space m+n
        // ListNode* tempA = a;
        // ListNode* tempB = b;
        // ListNode* c = new ListNode(100);
        // ListNode* tempC = c;
        // while(tempA != NULL && tempB != NULL){
        //     if(tempA->val <= tempB->val){
        //         ListNode* t = new ListNode(tempA->val);
        //         tempC->next = t;
        //         tempC = t;
        //         tempA = tempA->next;
        //     }
        //     else{
        //         ListNode* t = new ListNode(tempB->val);
        //         tempC->next = t;
        //         tempC = t;
        //         tempB = tempB->next;
        //     }
        // }
        // if(tempA == NULL){
        //     tempC->next = tempB;
        // }
        // else{
        //     tempC->next = tempA;
        // }
        // return c->next;

        //Method 2 using without extra space O(1)
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while(a != NULL && b != NULL){
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else{
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if(a == NULL) temp->next = b;
        else temp->next = a;
        return c->next;
    }
};
