#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
	
		int a[N+1], b[N+1];
		for(int i=1; i<=N; i++) {
			cin>>a[i];
			b[i]=a[i];	
		}
		
		sort(a+1, a+N+1);
		
		int p[M+1];
		p[M]=-1;
		for(int i=0; i<M; i++) cin>>p[i];
		sort(p, p+M);
		
		int L=p[0];
		for(int i=0; i<M; i++) {
			if(p[i]+1!=p[i+1]) {
				sort(b+L, b+p[i]+2);
				L=p[i+1];
			}
		}
		
		bool ans=true;
		for(int i=1; i<=N; i++) if(a[i]!=b[i]) ans=false;
		cout<<(ans ? "YES" : "NO")<<'\n';
	}

	return 0;
}
