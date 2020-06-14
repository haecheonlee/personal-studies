#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    int ans=1;
    
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    
    vector<int> b(n+1, 1);
    for(int i=n-1; i>=1; i--) {
        if(a[i+1]>a[i]) b[i]=b[i+1]+1;
        ans=max(ans, b[i]);
    }
    
    vector<int> c(n+1, 1);
    for(int i=2; i<=n; i++) {
        if(a[i-1]<a[i]) c[i]=c[i-1]+1;
        ans=max(ans, c[i]);
    }
    
    for(int i=1; i<=n-2; i++) {
        if(a[i]<a[i+2]) ans=max(ans, c[i]+b[i+2]);
    }
            
    cout<<ans;
    
	return 0;
}
