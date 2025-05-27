class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans = 0;
        for(string &word : words){
            string reverseWord = word;
            reverse(reverseWord.begin() , reverseWord.end());

            if(mp[reverseWord] > 0 ){
                ans += 4;
                mp[reverseWord]--;
            }
            else{
                mp[word]++;
            }
        }

        for(auto &it : mp){
            string word = it.first;
            int count = it.second;
            if(word[0] == word[1] && count > 0){
                ans += 2;
                break;
            }
        }
        
        return ans;
    }
};
