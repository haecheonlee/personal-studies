#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;

	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	vector<int> d(k+1,0);
	d[0]=1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=k; j++) {
			if(j-a[i]>=0) d[j]+=d[j-a[i]];
		}
	}
	cout<<d[k];

	return 0;
}

/*
INPUT:
3 10
1
2
5

OUTPUT:
10
*/
