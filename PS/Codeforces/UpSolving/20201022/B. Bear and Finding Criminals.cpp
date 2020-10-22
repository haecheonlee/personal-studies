#include <iostream>

using namespace std;

int main() {
	int N,K;
	cin>>N>>K;

	int a[N+1];
	for(int i=1; i<=N; i++) cin>>a[i]; 

	int ans=(a[K]==1);
	for(int i=1; i<N && (K-i>=1 || K+i<=N); i++) {
		int L = (K-i>=1 && a[K-i]==1 ? 1 : 0);
		int R = (K+i<=N && a[K+i]==1 ? 1 : 0);
		
		if(K-i>=1 && K+i<=N) ans+=((L+R==2) ? 2 : 0);
		else ans+=((L || R) ? 1 : 0);
	}
	cout<<ans;
	
	return 0;
}
