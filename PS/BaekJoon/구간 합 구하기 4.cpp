#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	int a[n];
	int sum[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i>0) sum[i]=a[i]+sum[i-1];
		else sum[i]=a[i];
	}
	
	int i,j;
	while(m--) {
		cin>>i>>j;
		i-=1;
		j-=1;
		
		if(i>0) cout<<sum[j]-sum[i-1]<<'\n';
		else cout<<sum[j]<<'\n';
	}

	return 0;
}

/*
boj.kr/11659

INPUT:
5 3
5 4 3 2 1
1 3
2 4
5 5

OUTPUT:
12
9
1
*/
