#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,K;
		cin>>N>>K;
		
		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		sort(a, a+N);
		
		int ans=0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(i==j) continue;
				int x=(K-a[j])/a[i];
				ans+=x;
				a[j]=a[j]+a[i]*x;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
