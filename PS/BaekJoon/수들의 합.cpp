#include <iostream>

using namespace std;

int main() {
	long long S, i=1;
	cin>>S;
	
	while((i*(i+1))<=(S*2)) {
		i++;
	}
	
	cout<<i-1;

	return 0;
}

/*
boj.kr/1789

INPUT:
200

OUTPUT:
19
*/
