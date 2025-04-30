class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i  = 0 ; i < nums.size() ; i++) {
            if (countDigits(nums[i]) % 2 == 0) count++;
        } 
        return count;
    }
    int countDigits(int x) {
        int cnt = 0;
        if(x == 0) return 1;
        while (x > 0) {
            x /= 10;
            cnt++;
        }
        return cnt;
    }
};
