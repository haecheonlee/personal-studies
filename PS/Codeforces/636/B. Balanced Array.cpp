/* Codeforces */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        int m=n/2;
        if(m%2!=0) cout<<"NO";
        else {
            cout<<"YES\n";
            for(int i=1; i<=m; i++) cout<<i*2<<" ";
            for(int i=1; i<m; i++) cout<<i*2-1<<" ";
            cout<<3*m-1<<" ";
        }
        cout<<'\n';
    }
    
	return 0;
}
