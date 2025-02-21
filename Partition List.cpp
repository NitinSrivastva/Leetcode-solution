class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo = new ListNode(100);
        ListNode* hi = new ListNode(200);
        ListNode* temp = head;
        ListNode* templo = lo;
        ListNode* temphi = hi;
        while(temp!=NULL){
            if(temp->val < x){
                templo->next = temp;
                temp = temp->next;
                templo = templo->next;
            }
            else{
                temphi->next = temp;
                temp = temp->next;
                temphi = temphi->next;
            }
        }
        templo->next = hi->next;
        temphi->next = NULL;
        return lo->next;
    }
};
