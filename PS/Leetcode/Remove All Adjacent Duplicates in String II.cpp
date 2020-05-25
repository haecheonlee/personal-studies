class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        
        for(auto &c : s) {
            if(stk.empty()) stk.push(make_pair(c,1));
            else {
                char letter=stk.top().first;
                int cnt=stk.top().second;
                
                if(letter==c) {
                    if(cnt+1==k) while(cnt--) stk.pop();
                    else stk.push(make_pair(c,cnt+1));
                } else {
                    stk.push(make_pair(c,1));
                }                
            }
        }
        
        string result="";
        while(!stk.empty()) {
            result+=stk.top().first;
            stk.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
