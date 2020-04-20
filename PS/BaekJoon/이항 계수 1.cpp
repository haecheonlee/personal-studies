#include <iostream>

using namespace std;

long long go(int n, int r) {
	if(n==r || r==0) return 1;
	return go(n-1,r-1)+go(n-1,r);
}

int main() {
	int n,r;
	cin>>n>>r;
	
	cout<<go(n,r);
	
	return 0;
}

/*
INPUT:
5 2

OUTPUT:
10
*/
