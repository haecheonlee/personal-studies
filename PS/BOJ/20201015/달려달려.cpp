/* reference: https://gkscode.tistory.com/63 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e4+1;
const int INF=1e9;

int N,M;
int a[MAX];
int cache[MAX][501];

int go(int n, int m) {
	if(n==N-m) return 0;
	if(n>N-m) return -INF;

	int& ret=cache[n][m];
	if(ret!=-1) return ret;
	ret=0;
	
	if(m<M) {
		if(m==0) {
			ret=max(go(n+1, m+1) + a[n], go(n+1, m));
		} else if(m>0) {
			ret=max(go(n+1, m+1) + a[n], go(n+m, 0));
		}
	} else if(m==M) {
		ret=go(n+m, 0);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	
	for(int i=0; i<N; i++) cin>>a[i];
	
	memset(cache, -1, sizeof(cache));
	cout<<go(0,0);
	
	return 0;
}
