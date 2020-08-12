/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;
const int MOD=1e9+7;

int d[5001][5001];
int main() {

	d[0][0]=1;
	for(int i=1; i<=5000; i++) {
		for(int j=0; j<=i; j++) {
			d[i][j]=0;
			if(j+1<=i) d[i][j]+=d[i-1][j+1];
			if(j-1>=0) d[i][j]+=d[i-1][j-1];
			d[i][j]%=MOD;
		}
	}

	int T;
	cin>>T;

	while(T--) {
		int N;
		cin>>N;
		
		cout<<d[N][0]<<'\n';
	}

	return 0;
}
