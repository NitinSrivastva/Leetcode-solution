class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if the list is empty or has only one node, return it as is
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // `newHead` will be the second node, as it will become the new head after swapping
        ListNode* newHead = head->next;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr != NULL && curr->next != NULL) {
            ListNode* nextPair = curr->next->next;  // Save the next pair
            ListNode* second = curr->next;          // Identify second node in the pair
            
            // Swap the two nodes
            second->next = curr;
            curr->next = nextPair;
            
            // Connect previous swapped pair to the new swapped pair
            if (prev != NULL) {
                prev->next = second;
            }
            
            // Move `prev` to `curr`, and `curr` to `nextPair`
            prev = curr;
            curr = nextPair;
        }
        
        return newHead;
    }
};
