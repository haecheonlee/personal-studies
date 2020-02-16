#include <iostream>

using namespace std;

int main() {
	int k,n,m;
	cin>>k>>n>>m;
	
	int total=k*n;
	cout<<((total>=m) ? total-m : 0);

	return 0;
}

/*
boj.kr/10156

INPUT:
300 4 1000

OUTPUT:
200
*/
