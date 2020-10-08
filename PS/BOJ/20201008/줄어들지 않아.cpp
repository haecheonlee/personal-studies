#include <iostream>

using namespace std;

long long d[65][10];

int main() {
	int T;
	cin>>T;
	
	for(int j=0; j<=9; j++) d[1][j]=1;
	for(int i=2; i<=64; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<=j; k++) d[i][j]+=d[i-1][k];
		}
	}

	while(T--) {
		int N;
		cin>>N;
		
		long long ans=0;
		for(int i=0; i<=9; i++) ans+=d[N][i];
		cout<<ans<<'\n';
	}
	
	return 0;
}
