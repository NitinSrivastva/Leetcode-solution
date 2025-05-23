class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> matrix(m, vector<int>(n, -1));
        int minr = 0, minc = 0;
        int maxr = m - 1, maxc = n - 1;
        ListNode* temp = head;

        while (minr <= maxr && minc <= maxc) {
            // Right
            for (int j = minc; j <= maxc; j++) {
                if(temp == NULL) return matrix;
                matrix[minr][j] = temp->val;
                temp = temp->next;
            }
            minr++;

            if (minr > maxr || minc > maxc) break;

            // Down
            for (int i = minr; i <= maxr; i++) {
                if(temp == NULL) return matrix;
                matrix[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;

            if (minr > maxr || minc > maxc) break;

            // Left
            for (int j = maxc; j >= minc; j--) {
                if(temp == NULL) return matrix;
                matrix[maxr][j] = temp->val;
                temp = temp->next;
            }
            maxr--;

            if (minr > maxr || minc > maxc) break;

            // Up
            for (int i = maxr; i >= minr; i--) {
                if(temp == NULL) return matrix;
                matrix[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++;
        }

        return matrix;
    }
};
