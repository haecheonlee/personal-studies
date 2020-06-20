/* Codeforces */

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--) {
        string s;
        cin>>s;
        
        int s1=0, s2=0;
        for(auto &it : s) {
            s1+=(it=='0');
            s2+=(it=='1');
        }
        
        int ans=min(s1,s2);
        int p1=0, p2=0;
        
        for(auto &it : s) {
            p1+=(it=='0'), s1-=(it=='0');
            p2+=(it=='1'), s2-=(it=='1');
            
            ans=min(ans, p2+s1);
            ans=min(ans, p1+s2);
        }
        cout<<ans<<'\n';
    }
    
	return 0;
}
