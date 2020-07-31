#include <iostream>

using namespace std;
using ll=long long;

const int MAX=1e6;

ll d[1000001];
ll total[1000001];

int main() {
	int N,K;
	cin>>N>>K;

	for(int i=0; i<N; i++) {
		int g,x;
		cin>>g>>x;
		
		d[x]=g;
	}
	
	for(int i=0; i<=MAX; i++) total[i]+=total[i-1]+d[i];
	
	ll ans=0;
	for(int i=0; i<=MAX; i++) {
		int left=max(0,i-K);
		int right=min(i+K,MAX);
		
		ans=max(ans,total[right]-total[left-1]);
	}
	cout<<ans;

	return 0;
}
