/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;

const int MAX=30;

int d[15][MAX][MAX];
int dx[]={-1,0,1,-1,0,1};
int dy[]={1,1,0,0,-1,-1};

int main() {
	d[0][14][14]=1;
	for(int K=1; K<=14; K++) {
		for(int i=0; i<MAX; i++) {
			for(int j=0; j<MAX; j++) {
				for(int L=0; L<6; L++) {
					int x=i+dx[L];
					int y=j+dy[L];
					
					if(0<=x && x<MAX && 0<=y && y<MAX)
						d[K][i][j]+=d[K-1][x][y];
				}
			}
		}
	}
	
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		cout<<d[N][14][14]<<'\n';
	}
	
	return 0;
}
