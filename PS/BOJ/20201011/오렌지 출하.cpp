/* reference: https://jason9319.tistory.com/314 */

#include <iostream>

using namespace std;
using ll=long long;

const int MAX=2e4+1;

ll a[MAX];
ll cache[MAX];

int main() {
	ll N,M,K;
	cin>>N>>M>>K;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	for(int i=1; i<=N; i++) {
		cache[i]=1e15;
		
		ll mx=a[i], mn=a[i];
		for(int j=i; j>=max(1LL, i-M+1); j--) {
			mx=max(mx, a[j]);
			mn=min(mn, a[j]);
			cache[i]=min(cache[i], cache[j-1] + K + (i - j + 1) * (mx-mn));
		}
	}

	cout<<cache[N];
	
	return 0;
}
