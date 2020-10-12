#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e4+1;
const int INF=1e9;

int N,M;
bool a[MAX];
int cache[MAX][250];

int go(int n, int jump) {
	// base case
	if(n==N) return 0;
	
	int& ret=cache[n][jump];
	if(ret!=-1) return ret;
	ret=INF;
	
	int px=jump-1, x=jump, nx=jump+1;
	if(px>0) {
		// x-1
		if(n+px<=N) {
			if(a[n+px]==false) {
				ret=min(ret, go(n+px, px) + 1);
			}
		}
	}
	
	// x
	if(n+x<=N) {
		if(a[n+x]==false) {
			ret=min(ret, go(n+x, x) + 1);
		}
	}
	
	// x+1;
	if(n+nx<=N) {
		if(a[n+nx]==false) {
			ret=min(ret, go(n+nx, nx) + 1);
		}	
	}
	
	return ret;
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;
		
		a[x]=true;
	}
	
	memset(cache, -1, sizeof(cache));
	int ans=go(1,0);
	cout<<((ans==INF) ? -1 : ans);
	
	return 0;
}
