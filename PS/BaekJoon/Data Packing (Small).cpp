#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	for(int j=1; j<=T; j++) {
		int N,X;
		cin>>N>>X;
		
		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		sort(a,a+N);
		
		int L=0, R=N-1;
		int ans=0;
		while(L<=R) {
			if(a[R]+a[L]>X) {
				R--;
			} else if(a[R]+a[L]<=X) {
				R--;
				L++;
			}
			ans++;
		}
		
		printf("Case #%d: %d\n", j, ans);
	}

	return 0;
}
