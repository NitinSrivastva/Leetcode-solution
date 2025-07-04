class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //step 1 : Finding the Pivot index
        int idx = -1;
        for(int i = n-2; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx == -1){ //if array is already greatest 
            reverse(nums.begin() , nums.end());
            return;
        }

        //Step 2 : sorting/reverse after pivot index
        reverse(nums.begin()+idx+1 , nums.end());

        //Step 3 : finding the greatest element just after pivot 
        int j = -1;
        for(int i = idx+1; i<n;i++){
            if(nums[i] > nums[idx]){
                j = i;
                break;
            }
        }
        //Step 4 : Swapping pivot idx and j (which is just greater than pivot)
        swap(nums[j] ,nums[idx]);
        return;
    }
};
