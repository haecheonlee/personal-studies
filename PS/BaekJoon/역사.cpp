#include <iostream>

using namespace std;

bool d[401][401];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		int from, to;
		cin>>from>>to;
		
		d[from][to]=true;
	}
	
	
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(d[i][k] && d[k][j]) d[i][j]=true;
			}
		}
	}
	
	cin>>m;
	while(m--) {
		int x,y;
		cin>>x>>y;
		
		if(d[x][y] && !d[y][x]) cout<<-1;
		else if(!d[x][y] && d[y][x]) cout<<1;
		else cout<<0;
		cout<<endl;
	}
	
	return 0;
}
