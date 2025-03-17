class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=2){
            if(nums[i] != nums[i+1])
            return false;
        }
        return true;
    }
};
