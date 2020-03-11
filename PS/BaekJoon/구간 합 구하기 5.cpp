#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	int a[n+1][n+1], sum[n+1][n+1];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			sum[i][j]=a[i][j]+sum[i][j-1];
		}
	}
	
	int x1,y1,x2,y2;
	while(m--) {
		cin>>x1>>y1>>x2>>y2;

		int result=0;
		for(int x=x1; x<=x2; x++) {
			result+=sum[x][y2]-sum[x][y1-1];
		}
		cout<<result<<'\n';
	}
	
	return 0;
}

/*
boj.kr/11660

INPUT:
4 3
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7
2 2 3 4
3 4 3 4
1 1 4 4

OUTPUT:
27
6
64
*/
