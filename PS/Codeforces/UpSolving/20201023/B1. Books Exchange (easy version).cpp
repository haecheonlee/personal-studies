#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int N;
		cin>>N;

		int p[N+1];
		for(int i=1; i<=N; i++) cin>>p[i];

		int ans[N+1];
		for(int i=1; i<=N; i++) {
			int cnt=1, x=p[i];
			while(x!=i) cnt++, x=p[x];
			ans[i]=cnt;
		}

		for(int i=1; i<=N; i++) cout<<ans[i]<<' ';
		cout<<'\n';
	}

	return 0;
}
