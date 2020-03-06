#include <iostream>

using namespace std;

long long d[100][100];
int a[100][100];

int main() {
	int n;
	cin>>n;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
		}
	}
	
	d[0][0]=1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(a[i][j]==0) continue;
			
			if(j+a[i][j]<n) {
				d[i][j+a[i][j]]+=d[i][j];
			}
			
			if(i+a[i][j]<n) {
				d[i+a[i][j]][j]+=d[i][j];
			}
		}
	}

	cout<<d[n-1][n-1];
	
	return 0;
}

/*
boj.kr/1890

INPUT:
4
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0

OUTPUT:
3
*/
