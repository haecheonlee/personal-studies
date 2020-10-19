/* reference: beakjoon/codeplus */

#include <iostream>

using namespace std;

const int MAX=1e2+1;
const int MIN=-32768*MAX;

int a[MAX];
int d[MAX][MAX];
bool check[MAX][MAX];

int go(int n, int m) {
	if(m==0) return 0;
	if(n<=0) return MIN;
	
	if(check[n][m]) return d[n][m];
	check[n][m]=true;
	int& ret=d[n][m];
	
	// including
	ret=go(n-1, m);
	
	// excluding
	int sum=0;
	for(int i=n; i>=1; i--) {
		sum+=a[i];
		ret=max(ret, go(i-2, m-1) + sum);
	}
	
	return ret;
}

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	cout<<go(N,M);
	
	return 0;
}
