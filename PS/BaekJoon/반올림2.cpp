#include <iostream>

using namespace std;

int main() {
	int n,num;
	cin>>n;

	for(int i=0; i<n; i++) {
		cin>>num;
		
		for(int i=10; i<num; i*=10) {
			bool r=((num%i/(i/10))>=5 ? true : false);
			num-=num%i;
			if(r) num+=i;
		}
		
		cout<<num<<'\n';
	}
	
	return 0;
}

/*
boj.kr/4539

INPUT:
9
15
14
4
5
99
12345678
44444445
1445
446

OUTPUT:
20
10
4
5
100
10000000
50000000
2000
500
*/
