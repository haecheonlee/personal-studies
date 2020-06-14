#include <iostream>

using namespace std;

int d[1001][1001];

int main() {
	int n,k;
	cin>>n>>k;

	for(int i=1; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			if(i==j || j==0) d[i][j]=1;
			else d[i][j]=d[i-1][j-1]+d[i-1][j];
			
			d[i][j]%=10007;
		}
	}
	
	cout<<d[n][k];

	return 0;
}
