#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e2+1;

int N,M,A,B;
int a[MAX][MAX];
int cache[MAX][MAX][300];

int go(int x, int y, int items) {
	if(x==N && y==M) {
		if(items==A) return 1;
		return 0;
	}
	
	int& ret=cache[x][y][items];
	if(ret!=-1) return ret;
	ret=0;
	
	int nx=x+1, ny=y+1;
	// right
	if(ny<=M) {
		if(a[x][ny]!=2) {
			int item=(a[x][ny]==1);
			ret+=go(x, ny, items + item);
		}
	}
	
	//up
	if(nx<=N) {
		if(a[nx][y]!=2) {
			int item=(a[nx][y]==1);
			ret+=go(nx, y, items + item);
		}
	}
	
	return ret;
}

int main() {
	cin>>N>>M>>A>>B;
	
	for(int i=0; i<A; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x][y]=1;
	}
	
	for(int i=0; i<B; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x][y]=2;
	}

	memset(cache, -1, sizeof(cache));
	cout<<go(1, 1, 0);

	return 0;
}
