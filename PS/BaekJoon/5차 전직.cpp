/* reference: wookje */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N,K;
	cin>>N>>K;

	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a, a+N);
	
	long long ans=0, sum=0;
	for(int i=N-1; i>=0; i--) {
		if(i<K) ans+=sum;
		sum+=a[i];
	}
	cout<<ans;

	return 0;
}
