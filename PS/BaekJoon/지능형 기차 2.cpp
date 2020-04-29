#include <iostream>

using namespace std;

int main() {
	int a,b;
	
	int sum=0,mx=0;
	while(cin>>a>>b) {
		sum+=b-a;
		mx=max(sum,mx);
	}
	cout<<mx;

	return 0;
}

/*
INPUT:
0 32
3 13
28 25
17 5
21 20
11 0
12 12
4 2
0 8
21 0

OUTPUT:
42
*/
