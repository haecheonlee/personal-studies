#include <iostream>

using namespace std;

int power2(int k) {
	return (1<<k);
}

int go(int n, int x, int y) {
	if(n==1) return 2*x+y;
	
	if(x<power2(n-1)) {
		if(y<power2(n-1)) return go(n-1,x,y);
		else return go(n-1,x,y-power2(n-1))+power2(2*n-2);
	} else {
		if(y<power2(n-1)) return go(n-1,x-power2(n-1),y)+power2(2*n-2)*2;
		else return go(n-1,x-power2(n-1),y-power2(n-1))+power2(2*n-2)*3;
	}
}

int main() {
	int n,x,y;
	cin>>n>>x>>y;
	
	cout<<go(n,x,y);
	
	return 0;
}

/*
INPUT:
3 7 7

OUTPUT:
63
*/
