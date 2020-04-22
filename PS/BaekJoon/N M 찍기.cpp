#include <iostream>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	int value=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout<<value++;
			if(j!=m) cout<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

/*
INPUT:
3 4

OUTPUT:
1 2 3 4
5 6 7 8
9 10 11 12
*/
