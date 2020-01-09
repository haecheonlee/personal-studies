#include <iostream>

using namespace std;

int primes[10001]{0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i=2; i<=10000; i++) {
		if(primes[i]==0) {
			for(int j=i+i; j<=10000; j+=i) primes[j]=1;
		}
	}
	
	int T,n;
	cin>>T;
	while(T--) {
		cin>>n;
		
		int l[2]{0, 100000};
		for(int p1=2; p1<=n/2; p1++) {
			int p2=n-p1;
			
			if(primes[p1]==0 && primes[p2]==0) {
				if((l[1]-l[0])>(p2-p1)) {
					l[0]=p1;
					l[1]=p2;
				}
			}
		}
		
		cout<<l[0]<<" "<<l[1]<<'\n';
	}

	return 0;
}

/*
boj.kr/9020

INPUT:
3
8
10
16

OUTPUT:
3 5
5 5
5 11
*/
