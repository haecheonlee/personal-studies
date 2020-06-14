#include <iostream>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	int d[n+1][n+1]{0};
	
	d[1][1]=1, d[2][1]=1, d[2][2]=1;
	for(int i=3; i<=n; i++) {
		d[i][1]=d[i][i]=1;
		for(int j=2; j<=i-1; j++) d[i][j]=d[i-1][j-1]+d[i-1][j];
	}
	
	cout<<d[n][k];
	
	return 0;
}
