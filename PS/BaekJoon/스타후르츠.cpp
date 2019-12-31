#include <iostream>

using namespace std;

int main() {
	int N, T, C, P;
	cin>>N>>T>>C>>P;
	
	int total=0;
	for(int i=1; i<=N; i+=T) {
		if(i==1) continue;
		total+=C;
	}
	
	int result = total*P;
	
	cout<<result;

	return 0;
}

/*
boj.kr/17496

INPUT:
60 10 300 1000

OUTPUT:
1500000
*/
