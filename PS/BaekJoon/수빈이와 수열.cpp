#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int num, result = 0;
	for(int i=1; i<=N; i++) {
		cin>>num;
		cout<< (num * i) - result  <<" ";
		result = num * i;
	}

	return 0;
}

/*
boj.kr/10539

INPUT:
5
1 2 2 3 4

OUTPUT:
1 3 2 6 8
*/
