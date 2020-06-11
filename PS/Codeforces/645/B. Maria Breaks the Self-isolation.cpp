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
        
        int current=1;
        int acc=0;
        for(int i=0; i<n; i++) {
            if(current>=a[i]) current++;
            else {
                if(current+acc>=a[i]) {
                    current+=acc+1;
                    acc=0;
                } else {
                    acc++;
                }
            }
        }
        cout<<current<<'\n';
    }
	return 0;
}
