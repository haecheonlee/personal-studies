#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    
    while(T--) {
        int N;
        cin>>N;
        
        int a[N];
        for(int i = 0; i < N; i++) cin>>a[i];
        
        if(N == 5) {
            long long ans = 1;
            for(int i = 0; i < N; i++) ans *= a[i];
            cout<<ans;
        } else {
            sort(a, a + N);
            long long ans = -1e18;
            
            for(int L = 0; L <= 5; L++) {
                long long total = 1;
                for(int i = 0; i < L; i++) total *= a[i];
                for(int i = N - 1; i >= N - 1 - (4 - L); i--) total *= a[i];
                ans = max(ans, total);
            }
            
            cout<<ans;
        }
        cout<<'\n';
    }

	return 0;
}
