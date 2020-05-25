class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        
        stack<int> s;
        for(int i=0; i<T.size(); i++) {
            if(!s.empty()) {
                while(!s.empty() && T[s.top()]<T[i]) {
                    result[s.top()]=i-s.top();
                    s.pop();
                }
            }
            s.push(i);
        }
        
        return result;
    }
};
