#include <iostream>

using namespace std;

int main() {
	int a,b,n,c;
	cin>>a>>b>>n;
	
	while(n--) {
		a%=b;
		a*=10;
		c=a/b;
	}
	cout<<c;

	return 0;
}

/*
INPUT:
25 7 5

OUTPUT:
2
*/
