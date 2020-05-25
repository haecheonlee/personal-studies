class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        const int SIZE=1e5+1;
        bool check[SIZE] {false};
        
        stack<int> stk;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') stk.push(i);
            else if(s[i]==')'){
                if(stk.empty()==false) {
                    int pos=stk.top();
                    
                    check[pos]=true;
                    check[i]=true;
                    stk.pop();
                }
            }
        }
        
        string result="";
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(' || s[i]==')') {
                if(check[i]) result+=s[i];
            } else {
                result+=s[i];
            }
        }
        return result;
    }
};
