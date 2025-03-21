class Solution {
public:
    string predictPartyVictory(string s) {
        int  n = s.length();
        queue<int>q; //push all the string index to the queue
        queue<int>r;//push all radiant string index to the r queue
        queue<int>d;//push all the dire string index to the d queue
        for(int i=0;i<n;i++){
            q.push(i);
            if(s[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(q.size()>1){
                if(s[q.front()] == 'X') q.pop();
                else if(s[q.front()] == 'R'){
                //check for victory of R
                if(d.size() == 0) return "Radiant";
                else{ // take rights of next D
                    s[d.front()] = 'X';
                    d.pop();

                    //Work is done
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
            }
            else{ // s[q.front()] == 'D'
                //Check for victory
                if(r.size() == 0) return "Dire";
                else{ // take rights of next "R"
                    s[r.front()] = 'X';
                    r.pop();

                    //Work is done 
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
        }
        if(s[q.front()] == 'R') return "Radiant";
        else return "Dire";
    }
};
