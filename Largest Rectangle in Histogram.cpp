class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n =arr.size();
        int nsi[n];
        stack<int>st;
        nsi[n-1] = n;
        st.push(n-1);
        for(int i =n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.size() == 0) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i); 
        }
    // again find the previous smaller index
        int psi[n];
        stack<int>s;
        psi[0] = -1;
        s.push(0);
        for(int i=1;i<n;i++){
            while(s.size()>0 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.size() == 0) psi[i] = -1;
            else psi[i] = s.top();
            s.push(i);
        }
        // Loop for maxarea
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int height = arr[i];
            int breadth = nsi[i] - psi[i] -1;
            int area = height * breadth;
            maxArea = max(maxArea , area);
        }
        return maxArea;
    }
};
