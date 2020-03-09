#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m,i,j;
	cin>>n;
	
	int a[n+1],sum[n+1];
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		
		if(i==0) sum[i]=a[i];
		else sum[i]=a[i]+sum[i-1];
	}
	
	cin>>m;
	while(m--) {
		cin>>i>>j;
		cout<<sum[j]-sum[i-1]<<'\n';
	}
	
	return 0;
}

/*
boj.kr/11411

INPUT:
5
10 20 30 40 50
5
1 3
2 4
3 5
1 5
4 4

OUTPUT:
60
90
120
150
40
*/
