#include <iostream>

using namespace std;

int main() {
	int d[1001];
	
	int n;
	cin>>n;
	
	int a[n+1];
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		d[i]=-1;
	}
	
	d[1]=0;
	for(int i=1; i<=n; i++) {
		int jump=a[i];
		for(int j=1; j<=jump; j++) {
			if(d[i+j]<d[i] && (i+j<=n)) d[i+j]=d[i]+1;	
		}
	}
	
	cout<<d[n];
	
	return 0;
}

/*
boj.kr/11060

INPUT:
10
1 2 0 1 3 2 1 5 4 2

OUTPUT:
5
*/
