#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int total=0;
	for(int i=1; i<=n; i++) {
		int count=1;
	
		for(int j=2; j*j<=i; j++) {
			if(i%j==0) { count++; }
		}
		
		total+=count;
	}
	
	cout<<total;

	return 0;
}

/*
boj.kr/8320

INPUT:
6

OUTPUT:
8
*/
