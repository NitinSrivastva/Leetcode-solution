class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fidx = -1;
        int sidx  = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(c == NULL) return{-1,-1};
        while(c != NULL){
            if(b->val > a->val && b->val >c->val || b->val < a->val && b->val < c->val){
                if(fidx == -1) fidx = idx;
                else sidx = idx;
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if(sidx == -1) return{-1,-1};
        int maxdistance = sidx - fidx;

        // For Minimum distance
        int mindistance = INT_MAX;
        fidx = -1;
        sidx  = -1;
        idx = 1;
        a = head;
        b = head->next;
        c = head->next->next;
        while(c != NULL){
            if(b->val > a->val && b->val >c->val || b->val < a->val && b->val < c->val){
               fidx = sidx;
               sidx = idx;
               if(fidx != -1){
                int distance = sidx - fidx;
                mindistance = min(mindistance,distance);
               }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        return {mindistance , maxdistance};
    }
};
