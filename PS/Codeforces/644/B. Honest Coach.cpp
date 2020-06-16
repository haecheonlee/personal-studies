#include <iostream>
#include <algorithm>

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
        sort(a, a+n);
        
        int result=a[n-1]-a[0];
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                result=min(result, a[j]-a[i]);
            }
        }
        cout<<result<<'\n';
    }
    
	return 0;
}
