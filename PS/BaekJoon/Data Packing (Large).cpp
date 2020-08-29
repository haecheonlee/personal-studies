#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	for(int current=1; current<=T; current++) {
		int N,X;
		cin>>N>>X;
		
		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		sort(a,a+N);
		
		
		int ans=0;
		int L=0, R=N-1;
		while(L<=R) {
			if(a[R]+a[L]>X) {
				R--;
			} else {
				L++;
				R--;
			}
			
			ans++;
		}
		
		printf("Case #%d: %d\n", current, ans);
	}

	return 0;
}
