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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is at the left middle
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL; // for breaking the list

        //merge these twp a and b alternatively

        ListNode* c = new ListNode(100);
        ListNode* tempc = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA != NULL && tempB != NULL){
            tempc->next = tempA;
            tempA = tempA->next;
            tempc = tempc->next;
            tempc->next = tempB;
            tempB = tempB->next;
            tempc = tempc->next;
        }
        tempc->next = tempA;
        head = c->next;
    }
};
