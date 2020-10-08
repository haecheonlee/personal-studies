#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e2+1;
const int MOD=1e5;

int N,M;
int d[MAX][MAX][3][2];
int dx[]={1,0};
int dy[]={0,1};

int go(int x, int y, int prev_dir, int turned) {
	// base case
	if(x>N || y>M) return 0;
	if(x==N && y==M) return 1;
	
	// caching
	int& ret=d[x][y][prev_dir][turned];
	if(ret!=-1) return ret;
	ret=0;
	
	for(int k=0; k<2; k++) {
		int nx=x+dx[k], ny=y+dy[k];
		
		if(x==1 && y==1) {
			ret+=(go(nx,ny,k,0)%MOD);
		} else {
			if(prev_dir!=k) {
				if(turned==0) ret+=(go(nx,ny,k,1)%MOD);
			}
			else {
				ret+=(go(nx,ny,k,0)%MOD);
			}
		}
		
		ret%=MOD;
	}
	
	return ret;
}

int main() {
	cin>>M>>N;

	memset(d, -1, sizeof(d));
	cout<<go(1,1,-1,0);

	return 0;
}
