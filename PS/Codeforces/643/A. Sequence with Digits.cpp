/* Codeforces */

#include <iostream>

using namespace std;
using ll=long long;

ll getAdd(ll b) {
    ll mn=10, mx=0;
    
    while(b>0) {
        ll a=b%10;
        b/=10;
        
        mn=min(mn,a);
        mx=max(mx,a);
    }
    
    return mn*mx;
}

int main() {
	  ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        ll a,k;
        cin>>a>>k;
        
        k--;
        while(k--) {
            ll b=getAdd(a);
            if(b==0) break;
            a+=b;
        }
        cout<<a<<'\n';
    }
    
	return 0;
}
