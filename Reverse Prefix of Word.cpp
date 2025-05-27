class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(word[i] == ch){
                ans = i;
                break;
            }
        }
        for(int i = 0;i < ans; i++){
            swap(word[i] , word[ans]);
            ans--;
        }
        return word;
    }
};
