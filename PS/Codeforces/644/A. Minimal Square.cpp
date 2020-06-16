#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        int a,b;
        cin>>a>>b;
        
        int v=min(max(2*a,b), max(a,2*b));
        cout<<v*v<<'\n';
    }
    
	return 0;
}
