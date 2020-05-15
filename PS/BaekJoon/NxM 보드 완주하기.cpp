#include <iostream>

using namespace std;

char a[33][33];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;

bool ok(int x, int y) {
	return 0<=x && x<n && 0<=y && y<m;
}

int go(int x, int y, int cnt) {
	int ans=-1;
	if(cnt==0) return 0;
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		while(ok(nx,ny) && a[nx][ny]=='.') {
			a[nx][ny]='#';
			cnt-=1;
			nx+=dx[k];
			ny+=dy[k];
		}
		
		nx-=dx[k];
		ny-=dy[k];
		if(!(x==nx && y==ny)) {
			int temp=go(nx,ny,cnt);
			if(temp!=-1) {
				if(ans==-1 || ans>temp+1) ans=temp+1;
			}
		}
		
		while(!(x==nx && y==ny)) {
			a[nx][ny]='.';
			cnt+=1;
			nx-=dx[k];
			ny-=dy[k];
		}
	}
	
	return ans;
}

int main() {
	int tc=1;
	while(cin>>n>>m) {
		int cnt=0;
		for(int i=0; i<n; i++) {
			cin>>a[i];
			
			for(int j=0; j<m; j++) {
				if(a[i][j]=='.') cnt+=1;
			}
		}
		
		int ans=-1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]=='.') {
					a[i][j]='#';
					
					int temp=go(i,j,cnt-1);
					if(temp!=-1) {
						if(ans==-1 || ans>temp) ans=temp;
					}
					a[i][j]='.';
				}
			}
		}
		
		cout<<"Case "<<tc<<": "<<ans<<endl;
		tc+=1;
	}

	return 0;
}
