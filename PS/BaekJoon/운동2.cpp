#include <iostream>

using namespace std;

int d[401][401];

int main() {
	int n,m;
	cin>>n>>m;
	
	while(m--) {
		int from, to, cost;
		cin>>from>>to>>cost;
		
		if(d[from][to]==0 || d[from][to]>cost) d[from][to]=cost;
	}
	
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(d[i][k]!=0 && d[k][j]!=0) {
					if(d[i][j]==0 || d[i][j]>d[i][k]+d[k][j]) {
						d[i][j]=d[i][k]+d[k][j];
					}
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=1; i<=n; i++) {
		if(d[i][i]!=0) {
			if(ans==-1 || ans>d[i][i]) ans=d[i][i];
		}
	}
	cout<<ans;
	
	return 0;
}
