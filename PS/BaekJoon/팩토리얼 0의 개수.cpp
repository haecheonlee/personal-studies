#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int total=0;
	for(int i=5; i<N; i*=5){
		total += N/i;
		if(N/i == 0) break;
	}
	
	cout<<total;
	return 0;
}

/*
boj.kr/1676

INPUT:
10

OUTPUT:
2
*/
