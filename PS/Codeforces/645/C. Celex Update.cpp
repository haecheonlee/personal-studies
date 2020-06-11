#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        long long x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        
        long long ans=(x2-x1)*(y2-y1)+1;
        cout<<ans<<'\n';
    }
    
	return 0;
}
