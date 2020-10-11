#include <iostream>

using namespace std;

const int MAX=2e3+1;
long long cache[11][MAX];

int main() {
	for(int j=1; j<MAX; j++) cache[1][j]=1;
	
	for(int i=2; i<=10; i++) {
		for(int j=1; j<MAX; j++) {
			for(int k=1; k*2<=j; k++) cache[i][j]+=cache[i-1][k];
		}
	}
	
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
		
		long long ans=0;
		for(int i=1; i<=M; i++) ans+=cache[N][i];
		cout<<ans<<'\n';
	}
	
	return 0;
}
