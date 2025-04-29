class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
        }
        //Use Sliding Window Technique
        long long ans = 0;
        int i = 0;
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(nums[j] == maxi) count++;

            while(count >= k)
            {
                ans += (n-j);

                if(nums[i] == maxi) count--;
                i++;
            }
        }
        return ans;
    }
};
