#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

vector<int> b;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	int a[N][M];
	bool check[N][M];
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	int t=0, ans=0;
	while(1) {
		memset(check, false, sizeof(check));
		queue<pi> q;
		q.push({0,0});
		
		bool found=false;
		ans=0;
		while(!q.empty()) {
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					if(check[nx][ny]==false) {
						check[nx][ny]=true;
						
						if(a[nx][ny]==0) {
							q.push({nx,ny});
						} else {
							found=true;
							a[nx][ny]=0;
							ans++;
						}
					}
				}
			}
		}
		
		if(found==false) break;
		b.push_back(ans);
		t++;
	}
	
	int piece=(b.empty()) ? 0 : b[b.size()-1];
	cout<<t<<'\n'<<piece;

	return 0;
}
