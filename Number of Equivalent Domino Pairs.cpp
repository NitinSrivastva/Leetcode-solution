class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> freq(100 , 0);
        int ans = 0;
        for(auto &d : dominoes){
            if(d[0] > d[1]) swap(d[0] , d[1]);
            int res = d[0]*10 + d[1];
            ans += freq[res];
            freq[res]++;
        }
        return ans;
    }
};
