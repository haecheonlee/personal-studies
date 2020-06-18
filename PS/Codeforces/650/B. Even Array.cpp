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
        int even=0, odd=0;
        for(int i=0; i<n; i++) {
            cin>>a[i];
                        
            if((a[i]%2)!=(i%2)) {
                if(i%2==0) odd++;
                else even++;
            }
        }
        
        if(even==odd) cout<<even<<'\n';
        else cout<<-1<<'\n';
    }
        
	return 0;
}
