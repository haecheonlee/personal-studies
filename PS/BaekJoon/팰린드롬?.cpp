#include <iostream>

using namespace std;

int d[2001][2001];
int a[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++) cin>>a[i];
	
	for(int i=1; i<=n; i++) d[i][i]=true;
	for(int i=1; i<=n-1; i++) {
		if(a[i]==a[i+1]) d[i][i+1]=true;
	}
	
	for(int k=3; k<=n; k++) {
		for(int i=1; i<=n-k+1; i++) {
			int j=i+k-1;
			if(a[i]==a[j] && d[i+1][j-1]) d[i][j]=true;
		}
	}
	
	int m;
	cin>>m;
	
	while(m--) {
		int s,e;
		cin>>s>>e;
		
		cout<<d[s][e]<<'\n';
	}

	return 0;
}
