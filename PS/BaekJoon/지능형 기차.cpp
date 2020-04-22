#include <iostream>

using namespace std;

int main() {
	int current=0;
	int mx=0;
	
	for(int i=0; i<4; i++) {
		int a,b;
		cin>>a>>b;
		current+=(b-a);		
		mx=max(mx,current);
	}

	cout<<mx;

	return 0;
}

/*
INPUT:
0 32
3 13
28 25
39 0

OUTPUT:
42
*/
