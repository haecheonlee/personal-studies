/* Codeforces */

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n,k;
        cin>>n>>k;
        
        while(k--) {
            bool check=false;
            for(int i=2; i<=n; i++) {
                if(n%i==0) {
                    if(i==2) check=true;
                    n+=i;
                    break;
                }
            }
            
            if(check) break;
        }
        
        if(k<0) cout<<n<<'\n';
        else cout<<n+(k*2)<<'\n';
    }
    
	return 0;
}
