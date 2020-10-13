#include <iostream>
#include <algorithm>

using namespace std;
using ll=long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		int N,K;
		cin>>N>>K;
		
		ll a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		sort(a, a+N);
		
		int L=max(0, N-2-(K-1));
		for(int i=N-2; i>=L; i--) a[N-1]+=a[i];
		cout<<a[N-1]<<'\n';
	}

	return 0;
}
