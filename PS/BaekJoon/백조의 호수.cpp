#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using PI=pair<int,int>;

queue<PI> water, nwater, swan, nswan;
bool wcheck[1501][1501];
bool scheck[1501][1501];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int n,m;
	cin>>n>>m;
	
	int x1,x2,y1,y2;
	x1=x2=y1=y2=-1;
	
	string a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
        for(int j=0; j<m; j++) {
            if(a[i][j]=='L') {
                if(x1==-1 && y1==-1) {
                    x1=i;
                    y1=j;
                }
                else {
                    x2=i;
                    y2=j;
                }

                a[i][j]='.';
            }
            
            if(a[i][j]=='.') {
                wcheck[i][j]=true;
                water.push(make_pair(i,j));
            }
        }
    }
	
	// start from one swan
	swan.push(make_pair(x1,y1));
	scheck[x1][y1]=true;
	
	for(int i=0;;i++) {
		while(!water.empty()) {
			int x,y;
			tie(x,y)=water.front();
			water.pop();
			
			a[x][y]='.';
			for(int k=0; k<4; k++) {
				int nx=dx[k]+x;
				int ny=dy[k]+y;
				
				if(0<=nx && nx<n && 0<=ny && ny<m) {
					if(wcheck[nx][ny]==false) {
						if(a[nx][ny]=='.') water.push(make_pair(nx,ny));
						else nwater.push(make_pair(nx,ny));
						wcheck[nx][ny]=true;
					}
				}
			}
		}
		
		while(!swan.empty()) {
			int x,y;
			tie(x,y)=swan.front();
			swan.pop();
			
			for(int k=0; k<4; k++) {
				int nx=dx[k]+x;
				int ny=dy[k]+y;
				
				if(0<=nx && nx<n && 0<=ny && ny<m) {
					if(scheck[nx][ny]==false) {
						if(a[nx][ny]=='.') swan.push(make_pair(nx,ny));
						else nswan.push(make_pair(nx,ny));
						scheck[nx][ny]=true;
					}
				}
			}
		}
		
		if(scheck[x2][y2]) {
			cout<<i;
			break;
		}
		
		water=nwater;
		swan=nswan;
		
		nwater=queue<PI>();
		nswan=queue<PI>();
	}
	
	return 0;
}
