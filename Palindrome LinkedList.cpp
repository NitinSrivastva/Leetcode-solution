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
    bool isPalindrome(ListNode* head) {
        // If the first half and the second half is reverse of the first half then it is palindrome
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
    // slow is at the left middle 
    ListNode* newHead = reverseList(slow->next);
    ListNode* a = head;
    ListNode* b = newHead;
    while(b != NULL){
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};
