#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,q,id,a,b;
	cin>>n>>q;
	
	int sum[n+1][4] {0};
	for(int i=1; i<=n; i++) {
		cin>>id;
		
		if(i>0) {
			for(int j=1; j<=3; j++) {
				sum[i][j]=sum[i-1][j];
			}
		}
		
		sum[i][id]+=1;
	}
	
	while(q--) {
		cin>>a>>b;
		
		for(int i=1; i<=3; i++) {
			cout<<sum[b][i]-sum[a-1][i]<<" ";
		}
		cout<<'\n';
	}
	
	return 0;
}

/*
INPUT:
6 3
2
1
1
3
2
1
1 6
3 3
2 4

OUTPUT:
3 2 1
1 0 0
2 0 1
*/
