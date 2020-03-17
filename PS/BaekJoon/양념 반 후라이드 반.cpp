#include <iostream>

using namespace std;

int main() {
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	
	int mn=x*a+y*b;
	for(int i=1; i<=100000; i++) {
		int result=((2*i)*c)+(max(0,x-i)*a)+(max(0,y-i)*b);
		mn=min(result,mn);
	}
	
	cout<<mn;
	
	return 0;
}

/*
INPUT:
1500 2000 1600 3 2

OUTPUT:
7900
*/
