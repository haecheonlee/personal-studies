#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	while(n!=1) {
		for(int i=2; i<=n; i++) {
			if(n%i==0) {
				cout<<i<<'\n';
				n/=i;
				break;
			}
		}
	}

	return 0;
}

/*
boj.kr/11653

INPUT:
72

OUTPUT:
2
2
2
3
3
*/
