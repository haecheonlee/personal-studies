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
        
        bool ok=false;
        for(int i=0; i<n; i++) {
            for(int j=i+2; j<n; j++) if(a[i]==a[j]) ok=true;
        }
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
	return 0;
}
