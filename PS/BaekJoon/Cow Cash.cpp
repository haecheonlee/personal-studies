#include <iostream>

using namespace std;
using ll=long long;

ll d[10001];

int main() {
	long long N,K;
	cin>>N>>K;
	
	ll a[N];
	for(int i=0; i<N; i++) cin>>a[i];

	d[0]=1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<=K; j++) {
			if(j-a[i]>=0) d[j]+=d[j-a[i]];
		}
	}
	cout<<d[K];

	return 0;
}
