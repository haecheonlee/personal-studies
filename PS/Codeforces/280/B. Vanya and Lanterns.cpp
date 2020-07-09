/* Codeforces */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,L;
    cin>>N>>L;
    
    int a[N];
    for(int i=0; i<N; i++) cin>>a[i];    
    sort(a,a+N);
    
    int ans=2*max(a[0],L-a[N-1]);
    for(int i=0; i<N-1; i++) {
        ans=max(ans, a[i+1]-a[i]);
    }
    printf("%.10f", (double)ans/2);
    
	return 0;
}
