/* Codeforces */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        int l=log2(n)+1;
        for(int i=2; i<=l; i++) {
            int x=(1<<i)-1;
            if(n%x==0) {
                cout<<n/x<<endl;
                break;
            }
        }
    }

	return 0;
}
