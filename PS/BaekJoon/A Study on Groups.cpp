/* reference: https://github.com/jonathanirvings/inc-2018/blob/master/groups/solution.cpp */

#include <iostream>
#include <algorithm>

using namespace std;
using ll=long long;

int main() {
	int N,K;
	cin>>N>>K;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	
	ll mn=0, mx=0;
	
	if(N<=K) {
		for(int i=0; i<N; i++) mn+=a[i];
		mx=mn;
	} else {
		sort(a, a+N);
		for(int i=0; i<K; i++) mn+=a[i];
		
		int x=0;
		for(int i=0; i<=N%K-1; i++) {
			mx+=a[x];
			x+=N/K+1;
		}
		
		for(int i=N%K; i<=K-1; i++) {
			mx+=a[x];
			x+=N/K;
		}
	}

	cout<<mn<<' '<<mx;
	
	return 0;
}
