#include <iostream>

using namespace std;

int ans=-1;
int N,M;
int a[10][10];

void go(int x, int y, int prev_dir, int sum) {
	if(y<0 || y>=M) return;
	if(x>=N) {
		if(ans==-1 || ans>sum) ans=sum;
		return;
	}
	
	int next_sum=sum+a[x][y];
	if(prev_dir!=0) go(x+1, y-1, 0, next_sum);	// left-down
	if(prev_dir!=1) go(x+1, y+0, 1, next_sum);	// straight-down
	if(prev_dir!=2) go(x+1, y+1, 2, next_sum);	// right-down
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	for(int j=0; j<M; j++) go(0,j,-1,0);
	cout<<ans;
	
	return 0;
}
