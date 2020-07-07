#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
		
		string a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		
		int ans=0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(a[i][j]=='>') {
					if(j+2>=M) continue;
					if(a[i][j+1]=='o' && a[i][j+2]=='<') ans++;
				} else if(a[i][j]=='v') {
					if(i+2>=N) continue;
					if(a[i+1][j]=='o' && a[i+2][j]=='^') ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
