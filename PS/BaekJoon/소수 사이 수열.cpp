#include <iostream>

using namespace std;

const int MAX=1300000;
bool notPrime[MAX]{false};

int main() {
	for(int i=2; i<MAX; i++) {
		if(notPrime[i]) continue;
		for(int j=i+i; j<MAX; j+=i) {
			notPrime[j]=true;
		}
	}
	
	int t,k;
	cin>>t;
	
	while(t--) {
		cin>>k;

		if(notPrime[k]) {
			int start=k,end=k;
			while(notPrime[--start]) {}
			while(notPrime[++end]) {}
			cout<<end-start<<'\n';
		} else {
			cout<<0<<'\n';
		}
	}
	
	return 0;
}

/*
boj.kr/3896

INPUT:
5
10
11
27
2
492170

OUTPUT:
4
0
6
0
114
*/
