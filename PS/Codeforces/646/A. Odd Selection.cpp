/* Codeforces */

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--) {
        int n,x;
        cin>>n>>x;
        
        int odd=0, even=0;
        for(int i=0; i<n; i++) {
            int a;
            cin>>a;
            
            if(a%2==0) even++;
            else odd++;
        }
        
        if(x==1) {
            if(odd>0) cout<<"Yes\n";
            else cout<<"No\n";
        } else if(x==2){
            if(odd>0 && even>0) cout<<"Yes\n";
            else cout<<"No\n";
        } else {
            bool check=false;
            for(int i=1; i<=odd; i+=2) {
                for(int j=0; j<=even; j++) {
                    if(j+i==x) {
                        check=true;
                        break;
                    }
                }
                if(check) break;
            }
            
            if(check) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

	return 0;
}
