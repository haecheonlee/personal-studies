#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n,greater<int>());
	for(int i=0; i<n; i++) cout<<a[i]<<'\n';

	return 0;
}

/*
INPUT:
5
1
2
3
4
5

OUTPUT:
5
4
3
2
1
*/
