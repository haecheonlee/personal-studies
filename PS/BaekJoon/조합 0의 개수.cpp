#include <iostream>

using namespace std;

long long countBy5(long long n) {
	long long count=0;
	for(long long i=5; i<=n; i*=5) {
		count+=n/i;
		if(n/i==0) break;
	}
	
	return count;
}

long long countBy2(long long n) {
	long long count=0;
	for(long long i=2; i<=n; i*=2) {
		count+=n/i;
		if(n/i==0) break;
	}
	
	return count;

}

int main() {
	long long n,m;
	cin>>n>>m;
	
	long long r=n-m;
	
	long long count1=countBy5(n);
	long long count2=countBy5(m)+countBy5(r);
	
	long long count3=countBy2(n);
	long long count4=countBy2(m)+countBy2(r);
	
	cout<<min(count1-count2,count3-count4);
	
	return 0;
}

/*
boj.kr/2004

INPUT:
25 12

OUTPUT:
2
*/
