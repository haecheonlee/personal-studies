#include <iostream>

using namespace std;

int n,m;
int idx[3];
bool check[70];
int area[8][8];
int dist[8][8];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int largest=0;

void dfs(int x, int y) {
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<m) {
			if(dist[nx][ny]==0) {
				dist[nx][ny]=2;
				dfs(nx,ny);
			}
		}
	}
}

void copyArray() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			dist[i][j]=area[i][j];
		}
	}
}

void go(int index, int start, int length) {
	if(index==3) {
		copyArray();
		
		for(int i=0; i<3; i++) {
			int x=idx[i]/m;
			int y=idx[i]%m;
			
			dist[x][y]=1;
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(area[i][j]==2) {
					dfs(i,j);
				}
			}
		}
		
		int count=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(dist[i][j]==0) count++;
			}
		}
		
		largest=max(largest,count);
		
		return;
	}
	
	for(int i=start; i<length; i++) {
		if(check[i]) continue;
		check[i]=true;
		int x=i/m;
		int y=i%m;
		if(area[x][y]!=0) continue;
		idx[index]=i;
		go(index+1,i,length);
		
		check[i]=false;
	}
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>area[i][j];
		}
	}
	
	go(0,0,n*m);
	cout<<largest;
	
	return 0;
}

/*
boj.kr/14502

INPUT:
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

OUTPUT:
27
*/
