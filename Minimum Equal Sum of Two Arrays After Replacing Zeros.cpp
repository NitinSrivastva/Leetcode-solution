class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        long long sum1_non_zero = 0;
        long long sum2_non_zero = 0;
        int count1 = 0;
        int count2 = 0;

        for (int x : nums1) {
            if (x == 0) {
                count1++;
            } else {
                sum1_non_zero += x;
            }
        }

        for (int x : nums2) {
            if (x == 0) {
                count2++;
            } else {
                sum2_non_zero += x;
            }
        }

        long long sum1 = sum1_non_zero + count1;
        long long sum2 = sum2_non_zero + count2;

        if (count1 == 0 && sum1_non_zero < sum2) {
            return -1;
        }
        if (count2 == 0 && sum2_non_zero < sum1) {
            return -1;
        }
        return max(sum1, sum2);
    }
};
