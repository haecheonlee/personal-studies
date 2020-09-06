#include <iostream>
 
using namespace std;
using ll=long long;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int a[N], b[N];
		int a_min=1e9+1, b_min=1e9+1;
		
		for(int i=0; i<N; i++) {
			cin>>a[i];
			a_min=min(a_min, a[i]);
		}
			
		for(int i=0; i<N; i++) {
			cin>>b[i];
			b_min=min(b_min, b[i]);
		}
		
		ll ans=0;
		for(int i=0; i<N; i++) {
			int common=max(a[i]-a_min, b[i]-b_min);
			ans+=common;
		}
		cout<<ans<<'\n';
	}
 
	return 0;
}
