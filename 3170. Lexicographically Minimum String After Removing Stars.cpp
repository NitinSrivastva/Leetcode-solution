class Solution {
public:
    class comparator {
    public:
        bool operator() (pair<char ,int> &p1 , pair<char ,int> &p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    
    typedef pair<char ,int> P;
    string clearStars(string s) {
        priority_queue<P,vector<P>,comparator> pq;

        for(int i = 0;i < s.size();i++){
            if(s[i] != '*'){
                pq.push({s[i] , i}); // {char , index}
            }
            else{
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*'; // marked visited
            }
        }
        string ans;
        for(int i = 0;i < s.size();i++){
             if(s[i] != '*'){
                ans.push_back(s[i]); // {char , index}
            }
        }
        return ans;
    }
};
