#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		long long a[n], b[m], c[n];
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<m; i++) cin>>b[i];
		
		sort(a,a+n);
		sort(b,b+m);
		
		long long sum=0;
		int j=0;
		for(int i=0; i<n; i++) {
			int distance=abs(a[i]-b[j]);
			
			while(j<m-1 && distance>abs(a[i]-b[j+1])) {
				distance=abs(a[i]-b[++j]);
			}
			
			sum+=b[j];
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}

/*
INPUT:
3
4 3
20 5 14 9
16 8 12
3 4
16 8 12
20 5 14 9
3 3
1 2 3
2 3 4

OUTPUT:
44
37
7
*/
