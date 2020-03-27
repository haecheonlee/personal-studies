#include <iostream>
#include <set>

using namespace std;
#define N 5

int a[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
set<int> ans;

void go(int x, int y, int sum, int count) {
	if(count==6) {
		ans.insert(sum);
		return;
	}
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<N && 0<=ny && ny<N) {
			go(nx,ny,sum*10+a[nx][ny],count+1);
		}
	}
}

int main() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>a[i][j];
	}	
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			go(i,j,a[i][j],1);
		}
	}
	
	cout<<ans.size();
	
	return 0;
}

/*
INPUT:
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1

OUTPUT:
15
*/
