class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n = arr.size();
        int count = 0;
        unordered_set<string> s;
        for(int  i = 0 ; i < n ; i++){
            s.insert(arr[i]);
        }
        for(int i = 0 ; i < n ; i++){
            string rev = arr[i];
            reverse(rev.begin() , rev.end());
            if(arr[i] == rev) continue;

            if(s.find(rev) != s.end()){
                count++;
                s.erase(arr[i]);
            }
        }
        return count;
    }
};
