#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e3+1;
const int INF=1e9;

int N;
int a[MAX][MAX];
int cache[MAX][MAX][3];

int getNextMilk(int milk) {
	if(milk==0) return 1;
	else if(milk==1) return 2;
	else return 0;
}

int go(int x, int y, int milk) {
	if(x>N || y>N) return 0;

	int& ret=cache[x][y][milk];
	if(ret!=-1) return ret;
	ret=0;
	
	int down, right;
	if(a[x][y]==milk) {
		// can buy
		int next_drink=getNextMilk(milk);
		down=max(go(x+1, y, next_drink) + 1, go(x+1, y, milk));
		right=max(go(x, y+1, next_drink) + 1, go(x, y, milk));
	} else {
        // cannot buy
		down=go(x+1, y, milk);
		right=go(x, y+1, milk);
	}
	
	ret=max(ret, max(down, right));

	return ret;
}

int main() {
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) cin>>a[i][j];
	}

	memset(cache, -1 ,sizeof(cache));
	cout<<go(1,1,0);

	return 0;
}
