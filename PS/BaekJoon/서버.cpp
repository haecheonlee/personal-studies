#include <iostream>

using namespace std;

int main() {
	int n, T;
	cin>>n>>T;
	
	int total = 0, num = 0, count = 0;
	for(int i=0; i<n; i++) {
		cin>>num;
		
		if(total + num > T) break;
		else { count++; total += num; }
	}

	cout<<count<<endl;

	return 0;
}

/*
boj.kr/10409

INPUT:
6 180
45 30 55 20 80 20

OUTPUT:
4
*/
