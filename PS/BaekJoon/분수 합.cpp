#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	int r1=a*d+b*c;
	int r2=b*d;
	
	int x=gcd(r1,r2);
	
	cout<<r1/x<<" "<<r2/x;
	
	return 0;
}

/*
INPUT:
2 7
3 5

OUTPUT:
31 35
*/
