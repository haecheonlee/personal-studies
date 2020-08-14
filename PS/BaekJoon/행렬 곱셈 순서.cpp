/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;

int a[1000][2];
int d[1000][1000];

int go(int x, int y) {
	if(d[x][y]) return d[x][y];
	if(x==y) return 0;
	
	if(x+1==y) return a[x][0]*a[x][1]*a[y][1];
	
	int &ans=d[x][y];
	ans=-1;
	for(int k=x; k<=y-1; k++) {
		int t1=go(x,k);
		int t2=go(k+1,y);
		
		int sum=t1+t2+a[x][0]*a[k][1]*a[y][1];
		if(ans==-1 || ans>sum) ans=sum;
	}
	return ans;
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) cin>>a[i][0]>>a[i][1];
	
	cout<<go(0,N-1);

	return 0;
}
