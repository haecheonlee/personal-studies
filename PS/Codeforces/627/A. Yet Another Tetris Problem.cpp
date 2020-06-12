#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        
        bool result=true;
        for(int i=1; i<n; i++) {
            if(a[0]%2!=a[i]%2) {
                result=false;
                break;
            }
        }
        
        if(result) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
	return 0;
}
