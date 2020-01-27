#include <iostream>
#include <algorithm>

using namespace std;

int rect[100][100];
bool check[100][100];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int result[100*100];
int m,n,k;

void dfs(int x, int y, int count) {
	rect[x][y]=count;
	check[x][y]=true;
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<m && 0<=ny && ny<n) {
			if(rect[nx][ny]==0 && check[nx][ny]==false) {
				dfs(nx,ny,count);
			}
		}
	}
}

int main() {
	cin>>m>>n>>k;

	int x1,y1,x2,y2;
	for(int v=0; v<k; v++) {
		cin>>x1>>y1>>x2>>y2;
		
		for(int i=y1; i<y2; i++) {
			for(int j=x1; j<x2; j++) {
				rect[i][j]=-1;
			}
		}
	}
	
	int count=0;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(rect[i][j]==0 && check[i][j]==false) {
				dfs(i,j,++count);	
			}
		}
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(rect[i][j]!=-1) result[rect[i][j]]+=1;
		}	
	}
	
	sort(result+1, result+count+1);
	cout<<count<<'\n';
	for(int i=1; i<=count; i++) cout<<result[i]<<" ";

	return 0;
}

/*
boj.kr/2583

INPUT:
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2

OUTPUT:
3
1 7 13
*/
