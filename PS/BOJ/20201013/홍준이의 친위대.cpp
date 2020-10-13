/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;
using ll=long long;

const int MAX=25;

ll c[MAX][MAX];
ll d[MAX];

ll go(int N) {
	ll& ret=d[N];
	if(ret!=-1) return d[N];
	ret=0;
	
	for(int i=1; i<=N; i+=2) {
		ret+=c[N-1][i-1] * go(i-1) * go(N-i);
	}
	
	return ret;
}

int main() {
	c[0][0]=1;
	for(int i=1; i<=20; i++) {
		c[i][0]=c[i][i]=1;
		for(int j=1; j<=i-1; j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	
	memset(d, -1, sizeof(d));
	d[0]=d[1]=d[2]=1;
	
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		if(N==1) cout<<1<<'\n';
		else cout<<2LL * go(N)<<'\n';
	}
	
	return 0;
}
