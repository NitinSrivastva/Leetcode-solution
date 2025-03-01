class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }
        int i=0;
        int j = 0;
        for(int k=0; k<nums.size(); k++){
            if(nums[k] != 0){
                nums[j] = nums[k];
                if(j != k) nums[k] = 0;
                j++;
            }
        }
        return nums;
    }
};
