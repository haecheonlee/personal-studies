#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	int a[n],b[m],merge[n+m];
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];
	
	int index_a=0, index_b=0;
	for(int i=0; i<n+m; i++) {
		if(index_a==n) {
			merge[i]=b[index_b++];	
		} else if(index_b==m) {
			merge[i]=a[index_a++];
		} else {
			if(a[index_a]<b[index_b]) merge[i]=a[index_a++];
			else merge[i]=b[index_b++];
		}
		
		cout<<merge[i]<<" ";
	}
	
	return 0;
}

/*
boj.kr/11728

INPUT:
4 3
2 3 5 9
1 4 7

OUTPUT:
1 2 3 4 5 7 9
*/
