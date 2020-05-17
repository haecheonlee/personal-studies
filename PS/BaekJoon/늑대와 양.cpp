#include <iostream>
#include <vector>

using namespace std;

int dx[]={0,0,1-1};
int dy[]={1,-1,0,0};

int main() {
	int n,m;
	cin>>n>>m;
	
	vector<string> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	bool ok=true;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]=='S') {
				for(int k=0; k<4; k++) {
					int x=i+dx[k];
					int y=j+dy[k];
					
					if(0<=x && x<n && 0<=y && y<m) {
						if(a[x][y]=='W') ok=false;
					}
				}
			}
		}
	}
	
	if(!ok) {
		cout<<0;
	} else {
		cout<<1<<'\n';
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]=='.') cout<<'D';
				else cout<<a[i][j];
			}
			cout<<'\n';
		}
	}

	return 0;
}
