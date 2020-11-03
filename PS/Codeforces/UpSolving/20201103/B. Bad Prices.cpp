#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int a[N];
		for(int i = 0; i < N; i++) cin>>a[i];
		
		int ans = 0, mn = a[N - 1];
		for(int i = N - 2; i >= 0; i--) {
			if(mn < a[i]) ans++;
			else mn = a[i];
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
