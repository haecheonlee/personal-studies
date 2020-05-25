class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        string result="";
        
        for(auto &c : s) {
            if(c=='(') stk.push('(');
            else if(c==')') {
                string reversed="";
                while(stk.top()!='(') {
                    reversed+=stk.top();
                    stk.pop();
                }
                
                // remove '(' 
                stk.pop();
                
                if(stk.empty()) result+=reversed;
                else for(auto &x : reversed) stk.push(x);
            } else {
                if(stk.empty()) result+=c;
                else stk.push(c);
            }
        }
        
        return result;
    }
};
