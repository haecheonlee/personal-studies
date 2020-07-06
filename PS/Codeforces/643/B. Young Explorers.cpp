#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		sort(a,a+N);
		
		int ans=0, cur=0;
		for(int i=0; i<N; i++) {
			if(++cur==a[i]) {
				ans++;
				cur=0;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
