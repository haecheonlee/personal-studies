#include <iostream>
#include <queue>

using namespace std;
using ll=long long;

int main() {
	int N,M;
	cin>>N>>M;
	
	priority_queue<ll> pq;
	for(int i=0; i<N; i++) {
		ll x;
		cin>>x;
		
		pq.push(-x);
	}

	while(M--) {
		ll x=-pq.top();
		pq.pop();
		ll y=-pq.top();
		pq.pop();
		
		ll sum=x+y;
		pq.push(-sum);
		pq.push(-sum);
	}
	
	ll ans=0;
	while(!pq.empty()) {
		ans+=-pq.top();
		pq.pop();
	}
	cout<<ans;

	return 0;
}
