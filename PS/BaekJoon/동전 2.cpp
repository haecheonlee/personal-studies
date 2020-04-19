#include <iostream>

using namespace std;

int a[101];
int d[10001];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=0; i<=m; i++) d[i]=-1;
	
	d[0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(j-a[i]>=0 && d[j-a[i]]!=-1) {
				if(d[j]==-1 || d[j]>d[j-a[i]]) d[j]=d[j-a[i]]+1;
			}
		}
	}
	cout<<d[m];
	
	return 0;
}

/*
INPUT:
3 15
1
5
12

OUTPUT:
3
*/
