/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

bool d[5001][5001];
int a[10];
int N,M;

void go(int i, int j) {
	if(i>N) return;
	if(d[i][j]) return;
	
	d[i][j]=true;
	for(int k=0; k<M; k++) go(i+j+a[k],j+a[k]);
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		cin>>N>>M;
		for(int i=0; i<M; i++) cin>>a[i];
		
		memset(d,false,sizeof(d));
		go(0,0);
		
		int ans=-1;
		for(int i=1; i<=N; i++) {
			if(d[N][i]) ans=i;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
