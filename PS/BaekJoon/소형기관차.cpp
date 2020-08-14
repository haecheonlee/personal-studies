/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;

int s[50001];
int a[50001];
int d[50001][4];

int sum(int x, int y) {
	return s[y]-s[x-1];
}

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	
	int M;
	cin>>M;
	
	for(int j=1; j<=3; j++) {
		for(int i=M*j; i<=N; i++) {
			d[i][j]=d[i-1][j];
			d[i][j]=max(d[i][j], d[i-M][j-1]+sum(i-M+1,i));
		}
	}
	cout<<d[N][3];
	
	return 0;
}
