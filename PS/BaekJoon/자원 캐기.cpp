#include <iostream>

using namespace std;

int a[301][301];
int d[301][301];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) cin>>a[i][j];
	}

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			d[i][j]=max(d[i-1][j],d[i][j-1])+a[i][j];
		}
	}
	cout<<d[N][M];

	return 0;
}
