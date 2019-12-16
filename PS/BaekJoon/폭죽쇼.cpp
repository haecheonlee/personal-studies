#include <iostream>
using namespace std;

int main() {
	int N, C;
	cin>>N>>C;
	
	int l[N], num = 0;
	for(int i=0; i<N; i++) {
		cin>>num;
		l[i] = num;
	}
	
	int count = 0;
	for(int i=1; i<=C; i++) {
		for(int j=0; j<N; j++) {
			if(i % l[j] == 0) {
				count++;
				break;
			}
		}
	}
	
	cout << count << endl;
	
	return 0;
}

/*
boj.kr/1773

INPUT:
2 20
4
6

OUTPUT:
7
*/
