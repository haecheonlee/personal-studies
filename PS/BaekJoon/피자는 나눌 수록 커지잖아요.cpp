#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	unsigned long long c;
	while(T--) {
		cin>>c;
		
		unsigned long long count=((c+1)*c)/2;
		unsigned long long total_pizza=((c*c)+c+2)/2;
		
		cout<<total_pizza-count<<'\n';
	}

	return 0;
}

/*
boj.kr/17946

INPUT:
2
1
2

OUTPUT:
1
1
*/
