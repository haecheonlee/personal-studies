/* Codeforces */

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    
    while(T--) {
        int x,y,n;
        cin>>x>>y>>n;
        
        if(n-n%x+y<=n) cout<<n-n%x+y<<endl;
        else cout<<n-n%x-(x-y)<<endl;
    }
    
	return 0;
}
