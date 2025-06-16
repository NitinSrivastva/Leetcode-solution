class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1; 
        int minElement = nums[0]; 
        for (int i = 1; i < n; i++) {
            if (nums[i] > minElement) {
                int diff = nums[i] - minElement;
                maxDiff = max(maxDiff, diff); 
            } else {
                minElement = nums[i]; 
            }
        }

        return maxDiff; 
    }
};
