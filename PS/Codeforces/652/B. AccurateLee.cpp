#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        string s;
        
        cin>>n>>s;
        int sw=1;
        for(int i=1; i<s.size(); i++) {
            if(s[i]<s[i-1]) sw=0;
        }
        
        if(sw) {
            cout<<s<<'\n';
            continue;
        }
        
        string ans;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') break;
            ans.push_back('0');
        }
        ans.push_back('0');
        
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i]=='0') break;
            ans.push_back('1');
        }
        cout<<ans<<'\n';
    }
    
	return 0;
}
