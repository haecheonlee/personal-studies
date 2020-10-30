#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {    
    int T;
    cin>>T;
    
    while(T--) {
        int N;
        cin>>N;
        
        int a[N];
        for(int i=0; i<N; i++) cin>>a[i];
        sort(a, a + N);
        
        ll p[N];
        for(int i=0; i<N; i++) {
            p[i] = a[i];
            if(i > 0) p[i] += p[i - 1];
        }
        
        ll ans = 0;
        for(int k=2; k<=N; k++) {
            ll total = 1e9;
            
            for(int i=k-1; i<N; i++) {
                ll diff = 1LL * a[i] * k - (p[i] - (i - k >= 0 ? p[i - k] : 0));
                if(total > diff) total = diff;
            }

            ans += total;
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
