#include <iostream>

using namespace std;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int main() {
	while(1) {
		int N,M;
		cin>>N>>M;
		
		if(N==0 && M==0) break;
		
		char a[N][M];
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) cin>>a[i][j];
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(a[i][j]=='*') continue;
				
				int mine=0;
				for(int k=0; k<8; k++) {
					int nx=i+dx[k];
					int ny=j+dy[k];
					
					if(0<=nx && nx<N && 0<=ny && ny<M) {
						if(a[nx][ny]=='*') mine++;
					}
				}
				a[i][j]=mine+'0';
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) cout<<a[i][j];
			cout<<'\n';
		}
	}

	return 0;
}
