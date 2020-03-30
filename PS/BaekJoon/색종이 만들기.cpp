#include <iostream>

using namespace std;

int a[150][150];
int cnt[2];

bool same(int x, int y, int n) {
	for(int i=x; i<x+n; i++) {
		for(int j=y; j<y+n; j++) {
			if(a[x][y]!=a[i][j]) return false;
		}
	}
	
	return true;
}

void solve(int x, int y, int n) {
	if(same(x,y,n)) {
		cnt[a[x][y]]+=1;
		return;
	}
	
	int m=n/2;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			solve(x+i*m,y+j*m,m);
		}
	}
}

int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}
	
	solve(0,0,n);
	for(int i=0; i<2; i++) cout<<cnt[i]<<'\n';
	
	return 0;
}

/*
INPUT:
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1

OUTPUT:
9
7
*/
