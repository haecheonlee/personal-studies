#include <iostream>

using namespace std;
using pii=pair<int,int>;

int main() {
	int N,K;
	cin>>N>>K;
	
	pii a[N];
	for(int i=0; i<N; i++) cin>>a[i].first>>a[i].second;
	
	long long ans=-1e12;
	for(int i=0; i<N; i++) {
		if(a[i].second > K) ans = max(ans, 1LL * a[i].first - (a[i].second - K));
		else ans = max(ans, 1LL * a[i].first);
	}
	cout<<ans;
	
	return 0;
}
