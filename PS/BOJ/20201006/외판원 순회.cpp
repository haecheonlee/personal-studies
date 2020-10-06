/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;

int d[(1<<20)][20];
int a[20][20];

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>a[i][j];
	}
	
	for(int i=0; i<(1<<N); i++) {
		for(int j=0; j<N; j++) d[i][j]=1e8;
	}
	
	d[1][0]=0;
	for(int i=0; i<(1<<N); i++) {
		for(int j=1; j<N; j++) {
			if(i&(1<<j)) {
				for(int k=0; k<N; k++) {
					if(k!=j && (i&(1<<k)) && a[k][j]!=0) {
						d[i][j]=min(d[i][j], d[i-(1<<j)][k]+a[k][j]);
					}
				}
			}
		}
	}
	
	int ans=1e9;
	for(int i=0; i<N; i++) {
		if(a[i][0]!=0) {
			ans=min(ans, d[(1<<N)-1][i]+a[i][0]);	
		}
	}
	cout<<ans;
	
	return 0;
}
