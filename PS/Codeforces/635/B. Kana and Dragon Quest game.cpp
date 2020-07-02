#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    
    while(T--) {
        int X, N, M;
        cin>>X>>N>>M;
        
        if(M==0) cout<<"NO\n";
        else {
            do {
                if(X-(M*10)<=0) {
                    X=0;
                    break;
                }
                X=(X/2)+10;
            } while(N--);
            
            if(X<=0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    
	return 0;
}
