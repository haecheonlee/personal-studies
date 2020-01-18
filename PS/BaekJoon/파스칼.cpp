#include <iostream>

using namespace std;

int main() {
	long long N, counter=1;
	cin>>N;

	for(long long i=2; i*i<=N; i++) {
		if(N%i==0) { 
			counter=N/i;
			break; 
		}
	}
	
	cout<<N-counter;

	return 0;
}

/*
boj.kr/2986

INPUT:
10

OUTPUT:
5
*/
