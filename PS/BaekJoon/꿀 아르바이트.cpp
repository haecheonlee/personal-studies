#include <iostream>

using namespace std;
using ll=long long;

int main() {
	int N,M;
	cin>>N>>M;
	
	int a[N];
	ll total=0;
	for(int i=0; i<N; i++) {
		cin>>a[i];
		if(i<M) total+=a[i];
	}
	
	ll ans=total;
	for(int i=M; i<N; i++) {
		total-=a[i-M];
		total+=a[i];
		
		ans=max(ans,total);
	}
	cout<<ans;
	
	return 0;
}
