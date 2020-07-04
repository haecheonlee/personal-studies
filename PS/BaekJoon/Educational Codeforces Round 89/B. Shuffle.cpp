/* Codeforces */

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    
    while(T--) {
        int N,X,M;
        cin>>N>>X>>M;
                
        int XL=X, XR=X;
        while(M--) {
            int L,R;
            cin>>L>>R;

            if(XL<=R && L<=XR) {
                XL=min(XL,L);
                XR=max(XR,R);
            }
        }
        
        cout<<XR-XL+1<<'\n';
    }
    
	return 0;
}
