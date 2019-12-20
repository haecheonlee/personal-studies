#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double N=0;
	cin>>N;
	
	int count = 1;
	while(N > 10) {
		N = round(N / pow(10, count)) * pow(10, count);
		if(N < pow(10, count+1)) break;
		count ++;
	}
	
	cout<<(long long)N;
}

/*
boj.kr/2033

INPUT:
15

OUTPUT:
20
*/
